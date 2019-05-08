pos = [-1 -1 2 2];
rectangle('Position',pos,'Curvature',[1 1])
axis equal
pos = [-1 -1 2 2];
hold off;
rectangle('Position',pos)
inside=0;
total=0;
points=[];
printf("Cantidad de iteraciones: ");
n=input(' ');
posX=-1+2*rand(1,n);
posY=-1+2*rand(1,n);
Mods=posY.^2+posX.^2;
for i=1:n
        if (Mods(1,i)<=1)
                inside+=1;
        endif
endfor
hold on;
format long g
PI=4*(inside/n)
plot(posX,posY,'r.')
axis equal