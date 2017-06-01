section .text
  global emulate_FileRepConnClient_CloseConnection
;.type emulate_FileRepConnClient_CloseConnection, @function
emulate_FileRepConnClient_CloseConnection:
  push rbp ; push the old base pointer
  mov rbp, rsp ; save the stack pointer
  inc rdi
  cmp rdi, 10; increment the counter by one
  jge end ;
  call emulate_FileRepConnClient_CloseConnection
end:
  leave
  ret
