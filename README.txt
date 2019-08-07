Bai1: Chuong trinh nhap vao 1 so nguyen co 3 chu so. In ra man hanh chu so theo thu tu gia dan
VD INPUT  291      
   OUTPUT 921
------------------------------------------------------------------------------------------------------------------------------------------
Bai2: In ra man hinh so ki tu la chu cai in hoa, so ki tu la chu cai thuong
VD INPUT  Xin chao tat ca Cac Ban
   OUTPUT So ki tu hoa: 3
	  So ki tu thuong: 15
------------------------------------------------------------------------------------------------------------------------------------------
Bai3: Chuong trinh tinh cuoc taxi, biet rang
      - Gia mo cua + km dau tien: 10.000VND
      - Moi 200m tiep theo: 1.500VND
      - Neu lon hon 30km thi moi km them tinh gia: 8.000VND
VD INPUT 750          INPUT 1250
   OUTPUT 10000VND    OUTPUT 11875VND
------------------------------------------------------------------------------------------------------------------------------------------
Bai4: In ra tam giac can co do cao h
VD INPUT 4

   OUTPUT         *
		 ***
                *****
	       *******
------------------------------------------------------------------------------------------------------------------------------------------

Bai5: Nhap: ngay, thang, nam kiem 
INPUT Ngay: 12       OUTPUT Nam nhuan
      Thang: 4
      Nam 3012

INPUT Ngay: 15     OUTPUT Khong hop le
      Thang: 15
      Nam: 3015
------------------------------------------------------------------------------------------------------------------------------------------
Bai6: Chuan hoa xau: dau va cuoi ko co dau cach, trong xau ko co dau cach thua, ko co 2 dau ',' hoac'.'
lien ke nhau, sau dau phay la khoang cach
VD INPUT " Xin  chao tat ca cac ban,minh la An"  
   OUTPUT "Xin chao tat ca cac ban, minh la an"
------------------------------------------------------------------------------------------------------------------------------------------
Bai7: Tim UCLN BCNN
VD INPUT   9 12
   OUTPUT  3 36
------------------------------------------------------------------------------------------------------------------------------------------
Bai8: Dao nguoc chuoi ki tu
VD INPUT "duy"
   OUTPUT "yud"
section .bss           ;Uninitialized data
   num resb 100
   lennum equ $-num
	stringnum resb 10
section .text
section .data
	usermsg db 'Nhap vao so thu 1: '
	lenmsg1 equ $-usermsg
	usermsg2 db 'Nhap vao so thu 2: '
	lenmsg2 equ $-usermsg2
	usermsg3 db 'Tong la: '
	lenmsg3 equ $-usermsg3
	
	
global _start
_start:
	
	mov ecx, usermsg
	mov edx, lenmsg1
	call sys_write
	
	mov ecx, num
	mov edx, lennum
	call sys_read
	
	mov edi, num
	call strlen
	mov ecx,eax
	
	mov esi,num
	call ConvertACSIItoBinary
	
	mov esi, stringnum
	call int_to_string
	
	mov ecx, stringnum
	mov edx, 10
	call sys_write
	 
	call sys_exit
	
;strlen function
;input: edi point to strings;
;output: eax = strlen(strings)
strlen:
	xor   rcx, rcx
_strlen_next:

	cmp   [rdi], byte 0  ; null byte yet?
	jz    _strlen_null   ; yes, get out

	inc   rcx            ; char is ok, count it
	inc   rdi            ; move to next char
	jmp   _strlen_next   ; process again

	_strlen_null:

	mov   rax, rcx       ; rcx = the length (put in rax)
	ret                  ; get out
; Input:
; ESI = pointer to the string to convert
; ECX = number of digits in the string (must be > 0)
; Output:
; EAX = integer value
ConvertACSIItoBinary:
	xor ebx,ebx
	.next_digit:
	movzx eax,byte[esi]
	inc esi
	sub al,'0'    ; convert from ASCII to number
	imul ebx,10
	add ebx,eax   ; ebx = ebx*10 + eax
	loop .next_digit  ; while (--ecx)
	mov eax,ebx
	ret

; Input:
; EAX = integer value to convert
; ESI = pointer to buffer to store the string in (must have room for at least 10 bytes)
; Output:
; EAX = pointer to the first character of the generated string	
int_to_string:
	add esi,9
	mov byte [esi],STRING_TERMINATOR

	mov ebx,10         
	.next_digit:
	xor edx,edx         ; Clear edx prior to dividing edx:eax by ebx
	div ebx             ; eax /= 10
	add dl,'0'          ; Convert the remainder to ASCII 
	dec esi             ; store characters in reverse order
	mov [esi],dl
	test eax,eax            
	jnz .next_digit     ; Repeat until eax==0
	mov eax,esi
	ret
  
sys_read:
	mov eax,3
	mov ebx,2
	int 80h
	ret
sys_write:
	mov eax,4
	mov ebx,1
	int 80h
	ret
sys_exit:
	mov eax,1
	mov ebx,0
	int 80h
https://stackoverflow.com/questions/19309749/nasm-assembly-convert-input-to-integer
