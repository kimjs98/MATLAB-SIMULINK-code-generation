id = zeros(1,360, 'int32');
x  = zeros(1,360, 'int32');
x(14) = 1;
for n = 1:360
    id(n) = x(n);
end
f1 = int32(find(id(1:25)));
f2 = int32(find(id(336:360)));
mn = int32(0);   mx = int32(0);
if size(f1) > 0
    f1 = sort(f1);
    mn = int32(min(f1));
end
if size(f2) > 0
    f2 = sort(f2);
    mx = int32(max(f2)); 
end
if mn == 0 || mx == 0
    if mn ~= 0
        y = mn;
    else
        y = mx;  
    end
elseif mn > abs(mx - 360)
    y = mx;
else
    y = mn;
end