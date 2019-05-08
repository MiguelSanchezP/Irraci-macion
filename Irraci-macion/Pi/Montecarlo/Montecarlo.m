pos = [-1 -1 2 2];
rectangle('Position',pos,'Curvature',[1 1])
axis equal
pos = [-1 -1 2 2];
hold off;
rectangle('Position',pos)
inside=0;
total=0;
points=[];
n=10000;
posX=-1+2*rand(1,n);
posY=-1+2*rand(1,n);
Mods=posY.^2+posX.^2;
for i=1:n
        %posX = -1 +(1+1)*rand(1,1);
        %posY = -1+(1+1)*rand(1,1);
        %points=[points: posX posY];
        %total+=1;
        %if (power(posX,i)+power(posY,i)<=1)
        if (Mods(1,i)<=1)
                inside+=1;
        endif
endfor
hold on;
%PI=4*(inside/total)
format long g
PI=4*(inside/n)
%plot([points(:,1)],[points(:,2)],'ro')
plot(posX,posY,'r.')
axis equal