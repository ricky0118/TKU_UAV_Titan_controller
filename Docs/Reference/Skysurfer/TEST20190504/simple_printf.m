function simple_printf
 s1=['%s%-*.*f%s%d' 10 0];  
 s2=['Time level ' 0];
 s3=['[s], Iterations: ' 0];
 iter = 32;
 time = 2.5;
 field_width=int32(20);
 precision=int32(3);
 coder.ceval('printf',s1,s2,field_width,precision,time,s3,int32(iter));