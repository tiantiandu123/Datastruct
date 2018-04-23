<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Index.aspx.cs" Inherits="Index" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .style1
        {
            width: 147px;
            text-align: center;
        }
        .style2
        {
            width: 147px;
            text-align: center;
            height: 35px;
        }
        .style3
        {
            height: 35px;
        }
        #Button2
        {
            text-align: center;
            height: 30px;
            width: 61px;
        }
        #Button1
        {
            height: 30px;
            width: 61px;
        }
        .style4
        {
            width: 515px;
        }
        .style7
        {
            text-align: center;
        }
        .style8
        {
            height: 122px;
        }
        #form1
        {
            height: 1069px;
        }
        .style9
        {
            width: 230px;
            height: 181px;
        }
        .style10
        {
            width: 230px;
            height: 268px;
        }
        .style11
        {
            width: 100%;
            height: 441px;
        }
        .style12
        {
            width: 100%;
            height: 377px;
        }
        .style13
        {
            width: 100%;
            height: 129px;
        }
        .style14
        {
            height: 32px;
        }
        .style15
        {
            height: 236px;
            text-align: center;
        }
        .style16
        {
            width: 510px;
        }
        .auto-style1 {
            width: 137%;
        }
        .auto-style3 {
            width: 488px;
            background-color: #FF66FF;
        }
        .auto-style4 {
            margin-left: 0px;
        }
        .style8 {
            background-image: url('images/images/陕西科技大学.jpg');
            background-repeat: inherit;
            background-attachment: inherit;
            background-position: center center;
        }
        .auto-style6 {
            height: 73px;
        }
       
        .auto-style7 {
            text-align: center;
            font-family: 楷体;
            font-size: medium;
            background-color: #FFCC66;
        }
       
        .auto-style8 {
            font-family: 楷体;
            font-size: x-large;
            color: #008080;
        }
       
        .auto-style9 {
            width: 103%;
            height: 181px;
        }
        .auto-style12 {
            font-family: 楷体;
            font-size: large;
        }
        .auto-style13 {
            height: 618px;
            width: 222px;
        }
        .auto-style14 {
            width: 153%;
            height: 303px;
            margin-right: 127px;
        }
        .auto-style15 {
            text-align: center;
            background-color: #FFCC66;
        }
        .auto-style16 {
            background-color: #FF66FF;
        }
        .auto-style17 {
            font-family: 华文楷体;
            font-size: large;
        }
        .auto-style18 {
            font-family: 隶书;
            font-style: italic;
            font-weight: bold;
            color: #9933FF;
            font-size: x-large;
        }
        .auto-style19 {
            font-weight: bold;
            color: #000000;
        }
        .auto-style20 {
            font-family: 楷体;
            font-size: medium;
        }
        .auto-style21 {
            width: 147px;
            text-align: center;
            height: 35px;
            font-family: 楷体;
            font-size: medium;
        }
       
    </style>
</head>
<body style="height: 1137px; width: 958px;">
    <form id="form1" runat="server">
    <div style="height: 985px; width: 952px;">
    
        <table class="auto-style1">
            <tr>
                <td colspan="14" 
                    style="text-align: center; font-family: 华文行楷; font-size: xx-large; color: #FF0000; background-image: url('images/images/陕西科技大学.jpg');" 
                    class="auto-style6">
                陕西科技大学网上书店管理系统</td>
            </tr>
            <tr style="background-color: #FFFF00">
                <td class="auto-style7">
                  图书类别</td>
                <td class="auto-style15">
                    <asp:HyperLink ID="HyperLink1" runat="server">儿童</asp:HyperLink>
                </td>
                <td class="auto-style15">
                    <asp:HyperLink ID="HyperLink2" runat="server">文学</asp:HyperLink>
                </td>
                <td class="auto-style15">
                    <asp:HyperLink ID="HyperLink3" runat="server">理学</asp:HyperLink>
                </td>
                <td class="auto-style15">
                    <asp:HyperLink ID="HyperLink4" runat="server">社科</asp:HyperLink>
                </td>
                <td class="auto-style15">
                    <asp:HyperLink ID="HyperLink5" runat="server">教育</asp:HyperLink>
                </td>
                <td class="auto-style15">
                    <asp:HyperLink ID="HyperLink6" runat="server">童话</asp:HyperLink>
                </td>
                <td class="auto-style15">
                    <asp:HyperLink ID="HyperLink7" runat="server">小说</asp:HyperLink>
                </td>
                <td class="auto-style15">
                    <asp:HyperLink ID="HyperLink8" runat="server">名著</asp:HyperLink>
                </td>
                <td class="auto-style15">
                    <asp:HyperLink ID="HyperLink9" runat="server">其他</asp:HyperLink>
                </td>
            </tr>
        </table>
        <table class="auto-style1">
            <tr style="background-color: #FF0000">
                <td style="text-align: center" class="auto-style3">
                    <asp:RadioButtonList ID="RadioButtonList1" runat="server" 
                        RepeatDirection="Horizontal" CssClass="auto-style4" Width="410px">
                        <asp:ListItem Selected="True">全部图书</asp:ListItem>
                        <asp:ListItem>特价图书</asp:ListItem>
                    </asp:RadioButtonList>
                </td>
                <td style="text-align: center" class="auto-style16">
                    欢迎光临本书店 
                    <asp:HyperLink ID="HyperLink34" runat="server" 
                        NavigateUrl="login_mananger.aspx">管理员</asp:HyperLink>
                </td>

            </tr>
        </table>
        <div style="height: 152px; width: 951px;">
            <asp:Image ID="Image8" runat="server" Height="152px" 
                ImageUrl='images/images/陕西科技大学.jpg' Width="1306px" />
        </div>
        <table class="auto-style14">
            <tr>
                <td class="style9">
                    <div class="auto-style13">
                    <table class="auto-style9">
                        <tr>
                            <td class="auto-style21">
                                用户名：</td>
                            <td class="style3">
                                <asp:TextBox ID="TextBox1" runat="server" Height="30px" Width="115px"></asp:TextBox>
                            </td>
                        </tr>
                        <tr>
                            <td class="auto-style21">
                                密 码：</td>
                            <td class="style3">
                                <asp:TextBox ID="TextBox2" runat="server" Height="30px" Width="113px" 
                                    TextMode="Password"></asp:TextBox>
                            </td>
                        </tr>
                        <tr>
                            <td class="style1">
                                <asp:Button ID="Button1" runat="server" onclick="Button1_Click" 
                                    Text="登录" CssClass="auto-style20" />
                            </td>
                            <td>
                                &nbsp;
                                </td>
                        </tr>
                    </table>
                    </div>
                </td>
                <td class="style16">
                    <span class="auto-style8">极力推荐</span><br />
                    <table class="style11">
                        <tr>
                            <td style="text-align: center">
                                <asp:ImageButton ID="ImageButton1" runat="server" ImageUrl="images/images/高代.jpg" 
                                    PostBackUrl="高代.aspx" />
                                <br />
                                <asp:HyperLink ID="HyperLink25" runat="server" 
                                    NavigateUrl="Book/高代.aspx" CssClass="auto-style19">高等代数</asp:HyperLink>
                                <br />
                                评分：<asp:Label ID="Label1" runat="server" 
                                    Text="5"></asp:Label>
                                <br />
                                价格：<asp:Label ID="Label2" runat="server" 
                                    Text="15"></asp:Label>
                            </td>
                            <td style="text-align: center">
                                <asp:ImageButton ID="ImageButton2" runat="server" 
                                    ImageUrl="images/images/高数.jpg" Height="262px" />
                                <br />
                                <asp:HyperLink ID="HyperLink26" runat="server" 
                                    NavigateUrl="Book/高数.aspx" CssClass="auto-style19">高等数学</asp:HyperLink>
                                <br />
                                评分:<asp:Label ID="Label3" runat="server" 
                                    Text="6"></asp:Label>
                                <br />
                                价格：<asp:Label ID="Label4" runat="server" 
                                    Text="27"></asp:Label>
                            </td>
                        </tr>
                        <tr>
                            <td style="text-align: center">
                                <asp:ImageButton ID="ImageButton3" runat="server" 
                                    ImageUrl="images/images/java.jpg" Height="209px" />
                                <br />
                                <asp:HyperLink ID="HyperLink27" runat="server" 
                                    NavigateUrl="Book/java.aspx" CssClass="auto-style19">JAVA</asp:HyperLink>
                                <br />
                                评分:<asp:Label ID="Label5" runat="server" 
                                    Text="7"></asp:Label>
                                <br />
                                价格:<asp:Label ID="Label6" runat="server" 
                                    Text="16"></asp:Label>
                            </td>
                            <td style="text-align: center">
                                <asp:ImageButton ID="ImageButton4" runat="server" ImageUrl="images//images/t01b140b238a60bf568.jpg" Height="197px" Width="159px" />
                                <br />
                                <asp:HyperLink ID="HyperLink28" runat="server" 
                                    NavigateUrl="Book/三重门.aspx" CssClass="auto-style19">三重门</asp:HyperLink>
                                <br />
                                  评分:<asp:Label ID="Label7" runat="server" 
                                    Text="7"></asp:Label>
                                <br />
                               价格:<asp:Label ID="Label8" runat="server" 
                                    Text="19"></asp:Label>
                            </td>
                        </tr>
                        
                    </table>
                </td>
                <td>
                    <span class="auto-style18">排行榜</span><br />
                    <table class="style12">
                        <tr>
                            <td>
                                1.
                                <asp:HyperLink ID="HyperLink14" runat="server" NavigateUrl="Book/三重门.aspx" CssClass="auto-style17">三重门</asp:HyperLink>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                2.
                                <asp:HyperLink ID="HyperLink15" runat="server" NavigateUrl="Book/Book2.aspx" CssClass="auto-style17">平凡的世界</asp:HyperLink>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                3.
                                <asp:HyperLink ID="HyperLink16" runat="server" NavigateUrl="Book/Book3.aspx" CssClass="auto-style17">人生</asp:HyperLink>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                4.
                                <asp:HyperLink ID="HyperLink17" runat="server" NavigateUrl="Book/Book4.aspx" CssClass="auto-style17">老生</asp:HyperLink>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                5.
                                <asp:HyperLink ID="HyperLink18" runat="server" NavigateUrl="Book/Book5.aspx" CssClass="auto-style17">极花</asp:HyperLink>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                6.
                                <asp:HyperLink ID="HyperLink19" runat="server" NavigateUrl="Book/Book6.aspx" CssClass="auto-style17">丑石</asp:HyperLink>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                7.
                                <asp:HyperLink ID="HyperLink20" runat="server" NavigateUrl="Book/Book7.aspx" CssClass="auto-style17">红高粱</asp:HyperLink>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                8.
                                <asp:HyperLink ID="HyperLink21" runat="server" NavigateUrl="Book/Book8.aspx" CssClass="auto-style17">高兴</asp:HyperLink>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                9.
                                <asp:HyperLink ID="HyperLink22" runat="server" NavigateUrl="Book/Book9.aspx" CssClass="auto-style17">火纸</asp:HyperLink>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                10.<asp:HyperLink ID="HyperLink23" 
                                    runat="server" NavigateUrl="Book/Book10.aspx" CssClass="auto-style17">怀念狼</asp:HyperLink>
                            </td>
                        </tr>
                    </table>
&nbsp;<asp:HyperLink ID="HyperLink24" runat="server" CssClass="auto-style12">更多&lt;&lt;</asp:HyperLink>
                    <br />
                    <asp:Image ID="Image7" runat="server" Height="152px" ImageUrl="images/images/8952533_201340475000_2.jpg" 
                        Width="193px" />
                </td>
            </tr>
            </table>
        <br />
    
    </div>
    </form>
</body>
</html>
