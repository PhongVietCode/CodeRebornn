## BEM
Stand for: Block Element Modifier
Element: Thanh phan trong khoi
Block: khoi
Modifier: Khoi co mau thanh cong hay that bai

## Cu phap
.block
.block__element

.block--modifier
.block__element--modifier
 ## BLock long nhau
 __Bold__
 **Bold**
 *italic*
_italic phong_

`inlinecode`
> block quote

- `align-items`: thay doi kieu tru tren xuong duoi 
- `justify-content`: thay doi tu trai sang phai
- `align-content`: set how multiple lines are space apart from each other.
-`flex-direction`: chinh row hoac column (reverse)
-`flex-wrap`: co cho xuong dong khong khi khong du cho
-`flex-flow`: ket hop giua flex-direction va flex-wrap, syntax:  direction+wrap

# Binary Search 
__3 part of a binary search__
1. if the list if unsorted, we should sort it before search by start,end and middle
2. use a loop or a recursion to divide search space in half after each comparison
3. determine the target in the remaining space
# Binary search 
1. Luôn nhớ check xem node có null hay k mới cho vào
# Dynamic Programming
-> Tạo ra một cái array mà lưu các giá trị đã tính của 1 hàm
để sau đó sử dụng lại
## Part 1: Memoization

## Part 2: Tabulation

## Part 3: Top-down approach

## Part 4: Bottom-up approach

## Part 5: 2 variables jump

__Nhớ cái return nha__
### Các bước làm 1 bài toán dynamic programming -> Nên học thuần thục Recursion trước

_B1_: Phải giải được bài toán theo cách đệ quy trước
_B2_: Thêm 1 array để lưu trữ dữ liệu làm giảm time complexity đi
`Check xem no co trong array chua, chua có thi lam phep tinh de them vào`

### Merge Sort (25/8/2022)
- Chia đôi cái array ra
- chia đôi sub array cho đến khi chỉ còn lại 2 phần tử trong subarray
- so sánh 2 phần tử đó
- xong so sánh đít thằng này đầu thằng kia
- xong có 2 cái pointer cho 2 sub array đã so sánh ban đầu
- so sánh từng phần tử của từng subarray rồi để vào array cũ