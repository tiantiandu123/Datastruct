<%@ Page Language="C#" AutoEventWireup="true" CodeFile="login_mananger.aspx.cs" Inherits="login_mananger" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 842px;
            height: 392px;
            margin-left: 115px;
        }
        .auto-style2 {
            font-family: 楷体;
            font-size: xx-large;
        }
        .auto-style3 {
            font-family: 楷体;
            font-size: x-large;
            width: 147px;
        }
        .auto-style4 {
            width: 147px;
        }
        .auto-style5 {
            background-color: #99FF99;
            background-image: url('images/55730b847cd77_1024.jpg');
        }
        .auto-style6 {
            font-size: xx-large;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div class="auto-style5">
    
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="auto-style6"> </span><span class="auto-style2">管理员登录</span><br />
    <table class="auto-style1">
                        <tr>
                            <td class="auto-style3">
                                用户名：</td>
                            <td class="style3">
                                <asp:TextBox ID="TextBox1" runat="server" Height="30px" Width="204px"></asp:TextBox>
                            </td>
                        </tr>
                        <tr>
                            <td class="auto-style3">
                                密 码：</td>
                            <td class="style3">
                                <asp:TextBox ID="TextBox2" runat="server" Height="30px" Width="203px" 
                                    TextMode="Password"></asp:TextBox>
                            </td>
                        </tr>
                        <tr>
                            <td class="auto-style4">
                                <asp:Button ID="Button1" runat="server" onclick="Button1_Click" 
                                    Text="登录" CssClass="auto-style20" style="font-family: 楷体; font-size: x-large" />
                            </td>
                            <td>
                                &nbsp;</td>
                        </tr>
                    </table>
    </div>
    </form>
</body>
</html>
