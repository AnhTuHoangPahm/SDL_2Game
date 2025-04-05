BÁO CÁO BÀI TẬP LỚP MÔN LẬP TRÌNH NÂNG CAO  
  
Sinh viên:  Hoàng Phạm Anh Tú.   		
Sinh ngày: 09/10/2006  
Ngành học: Lập trình nâng cao.    		
Lớp: INT2215 3  
Chuyên ngành: Khoa học máy tính.   
Tên game : Alpha.  
LỐI CHƠI, LOGIC CỦA GAME:  
- Bản đồ được chia thành các ô vuông, di chuyển nhân vật bằng phím mũi tên, mỗi lần di chuyển là 1 ô.  
- Người chơi chỉ có 1 mạng, cần phải sống trong 1 khoảng thời gian nhất định trong bản đồ với các kẻ địch sinh ra ngẫu nhiên và không ngừng.  

CẤU TRÚC PROJECT CỦA GAME:
- assets:  chứa đồ họa dùng trong game.  
- build:  chứa file thực thi (.exe).  
- include:  chứa các header file cần thiết (có sẵn, SDL2, tự định nghĩa).  
- lib:  chứa các thư viện tĩnh (static library) cần thiết.  
- src:  chứa source code.  
- ttfont:  chứa TrueType Font.  
- Các file .dll (Dynamic-link library) để trong thư mục project gốc: đảm bảo chương trình có thể tìm và load thư viện SDL2.   
- Game được lập trình trên VSCode, do đó có thư mục .vscode, gồm:  
  - task.json:  Tiết kiệm thời gian viết lệnh để biên dịch chương trình.  
  - launch.json:  debug và chạy chương trình ngay sau khi đã được biên dịch.  
  - các tệp còn lại là các cài đặt bổ sung cho trình biên dịch (includePath, v.v).  
  (file .json đã được chỉnh sửa cho phù hợp).  

CÁC CHỨC NĂNG ĐÃ CÀI ĐƯỢC CHO GAME:  
- Tạo 1 cửa sổ và render bản đồ, các nhân vật trong cửa sổ đó.  
- Điều khiển nhân vật (phím mũi tên).  
- Kẻ địch được sinh ngẫu nhiên và di chuyển ngẫu nhiên.  
- Collision (va chạm): khi kẻ địch tấn công người chơi, khiến người chơi văng ra ngoài map (dead).  
- Cuộn map.(DELETED)

NGUỒN THAM KHẢO:  
- Inspirers: Onebit Advecture: https://www.onebitadventure.com/    
- Code:   
Let's Make Games: https://youtube.com/playlist?list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&si=T6MJcd_q24fXCLI4  
codergopher: https://youtube.com/playlist?list=PL2RPjWnJduNmXHRYwdtublIPdlqocBoLS&si=XcONj5GbX989q5NI  
LazyFoo: https://lazyfoo.net/tutorials/SDL/index.php
AI: Copilot, ChatGPT.  
- Assets:   
Grass: https://codespree.itch.io/seamless-rpg-tiles  
  
  
NHẬN XÉT CỦA NGƯỜI TEST  
...................................................................................................................  
...................................................................................................................   
