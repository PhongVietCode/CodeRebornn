## Bài toán tìm tổng có số cuối cùng bằng 3 -> suy luận cắt xén
- Vì chỉ xét chữ số cuối cùng nên là sẽ chỉ để ý đến chữ số cuối cùng của các ptu trong mảng
- Vì chỉ lấy 3 số thôi nên là mỗi loại chữ số cuối cùng từ 1 tới 10 thì chỉ lấy ít hơn hoặc bằng 3 số
- Các chữ số còn lại bỏ
## Bài toán mảng tổt -> Suy luận cắt xén
- Ví dụ mảng có 3 ptu:
- Nếu có 3 ptu lớn hơn 0 thì tổng 3 ptu sẽ không bao giờ có trong mảng
-> Mảng sẽ chỉ có 2 ptu lớn hơn 0 hoặc 2 ptu bé hơn 0(tương tự)
- Đối với những ptu bằng 0 cũng chỉ cần xét 2 ptu vì khi cộng với bất cứ 1 thằng nào nữa thì cũng sẽ ra chính thằng đó thôi
## Dãy số 3 -> QHĐ
- Số 3 nó chỉ chia hết cho 1 và chính nó
- Nếu số đó chia hết cho 2 và 5 thì sẽ không bao h chia hết cho 3
- Nếu số đó không chia hết cho 2 và 5 thì sẽ luôn tồn tại số chia hết cho n có ít hơn n số 3

r[i] = 333...3 (i số 3)
VD : r[1] = 3 % 11;
    r[2] = 33 % 11;
    r[3] = 333 % 11;
    ...
-> r[i] = (10 * r[i-1] + 3) % 11;
## Tần suất lẻ -> sử dụng phép toán XOR
1. XOR: giống ra 0 khác ra 1
2. Dấu hiệu dùng XOR là tần suất, khác nhau giống nhau,...
## Mảng tăng dần
1. Luôn có 1 số bằng 0 trong mảng cuối cùng 
2. Vì a[i] luôn dương nên bên trái b[i] == 0 ta -a[i], bên phải +a[i]

B1: Chọn 1 vị trí i trong mảng b -> cố định số 0
B2: Chỉ cần for xong cộng trừ vừa đủ
