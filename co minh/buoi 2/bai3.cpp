#include <iostream>
using namespace std;
int x[11], d[11], a[11], n, k;

void init ()
{
    cin >> k >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

void output()
{
    for (int i = 1; i <= k; i++)
    {
        cout << a[x[i]] << " ";
    }
    cout << endl;
}

void tim(int i)  // Hàm đệ quy để sinh các tổ hợp
{
    for (int j = 1; j <= n; j++)  // Duyệt qua từng vị trí trong mảng
    {
        if (d[j] == 0)  // Kiểm tra xem vị trí j đã được chọn chưa
        {
            x[i] = j;   // Lưu vị trí j vào tổ hợp hiện tại
            d[j] = 1;   // Đánh dấu vị trí j đã được sử dụng
            if (i == k)  // Nếu đã chọn đủ k phần tử
            {
                output();  // In ra tổ hợp hiện tại
            }
            else tim(i + 1);  // Nếu chưa đủ k phần tử thì tiếp tục đệ quy
            d[j] = 0;   // Đặt lại trạng thái để thử các tổ hợp khác
        }
    }
}

int main()
{
    freopen("so.inp", "r", stdin);
    freopen("so.out", "w", stdout);
    init();
    tim(1);
}
