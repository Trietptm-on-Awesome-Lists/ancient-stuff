
?debug          macro   ; to avoid tasm warnings/errors
                endm

locals          __


repXXX          macro   xxx, jcc
                local   cycle, exit, quit

                t       = 0
                ifidni  <"&xxx">,<"movsb">
                t       = 1
                endif
                ifidni  <"&xxx">,<"stosb">
                t       = 1
                endif

                if      t eq 1

                pushf
cycle:          or      ecx, ecx
                jz      exit
                xxx
                dec     ecx
                jmp     cycle
exit:           popf

                else

cycle:          pushf
                or      ecx, ecx
                jz      exit
                popf

                xxx

                lea     ecx, [ecx-1]

                jcc     quit
                jmp     cycle

exit:           popf
quit:

                endif

                endm

repz            macro   sux
                repXXX  sux, jnz
                endm

repnz           macro   sux
                repXXX  sux, jz
                endm


;WHILE CountReg <> 0
;DO
;  �믮������ �ਬ�⨢��� ��ப���� �������;
;  CountReg <- CountReg - 1;
;  IF �ਬ�⨢��� ������ �� CMPB,CMPW,SCAB ��� SCAW
;  THEN
;    IF (������� REP/REPE/REPZ) AND (ZF=1)
;    THEN ��室 �� 横�� WHILE
;    ELSE
;      IF (������� REPNZ ��� REPNE) AND (ZF=0)
;      THEN ��室 �� 横�� WHILE;
;      FI;
;    FI;
;  FI;
;OD;


rep             macro   xxx
                repz    xxx
                endm

repe            macro   xxx
                repz    xxx
                endm

repne           macro   xxx
                repnz   xxx
                endm




