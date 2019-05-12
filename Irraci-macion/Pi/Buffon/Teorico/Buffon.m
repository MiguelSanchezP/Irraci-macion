printf ("Cantidad de iteraciones: ");
iter = input(' ');
longitud = 10;
espaciado = 10;
puntosX =100*rand(1,iter);
puntosY =100*rand(1,iter);
angulos = -(pi/2)+pi*rand(1,iter);
puntosFinX = puntosX.+longitud.*cos(angulos);
puntosFinY = puntosY.+longitud.*sin(angulos);
residuosInicial = fix(puntosX/espaciado);
residuosFinal = fix(puntosFinX/espaciado);
cruces = 0;
for i=1:1:iter
  if !(residuosInicial(i) == residuosFinal(i))
    cruces += 1;
  endif
  hold on
  plot ([puntosX(i) puntosFinX(i)],[puntosY(i) puntosFinY(i)])
endfor
for i=0:espaciado:100+longitud
  hold on
  plot ([i i],[0 100+longitud],'k')
endfor
axis equal
PI = (2*iter*longitud)/(cruces*espaciado)
printf ("Cantidad de cruces: %d\n", cruces);
printf ("Cantidad de NO cruces: %d\n", iter-cruces);