<%@ Page Language="C#" AutoEventWireup="true" Debug ="true" CodeFile="curriculum.aspx.cs" Inherits="curriculum" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>

    <style type="text/css">
        .style1
        {
            width: 100%;
        }
        .auto-style1 {
            font-family: 楷体;
            font-weight: bold;
            font-size: medium;
            margin-left: 407px;
        }
        .auto-style2 {
            background-image: url('images/61.jpg');
        }
        .auto-style3 {
            margin-left: 260px;
        }
        .auto-style4 {
            margin-left: 264px;
        }
        .auto-style5 {
            height: 888px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server" class="auto-style2">
    <div id ="left">
        <asp:Button ID="Button1" runat="server" onclick="Button1_Click" Text="查看用户信息" CssClass="auto-style1" Height="28px" Width="278px" />
        <br />
        <br />
    </div>
    <div id="right" class="auto-style5">
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" CellPadding="4" Height="194px" Width="1028px" GridLines="None" CssClass="auto-style3" ForeColor="#333333">
            <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
            <Columns>
                <asp:BoundField DataField="书名" HeaderText="书籍名称" SortExpression="文本" />
                <asp:BoundField DataField="出版社" HeaderText="出版社" SortExpression="文本" />
                <asp:BoundField DataField="类别" HeaderText="类别" SortExpression="文本" />
                <asp:BoundField DataField="价格" HeaderText="价格" SortExpression="文本" />
                <asp:BoundField DataFormatString="作者" HeaderText="作者" SortExpression="文本" />
            </Columns>
            <EditRowStyle BackColor="#999999" />
            <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
            <PagerStyle BackColor="#284775" ForeColor="White" HorizontalAlign="Center" />
            <RowStyle BackColor="#F7F6F3" ForeColor="#333333" />
            <SelectedRowStyle BackColor="#E2DED6" Font-Bold="True" ForeColor="#333333" />
            <SortedAscendingCellStyle BackColor="#E9E7E2" />
            <SortedAscendingHeaderStyle BackColor="#506C8C" />
            <SortedDescendingCellStyle BackColor="#FFFDF8" />
            <SortedDescendingHeaderStyle BackColor="#6F8DAE" />
        </asp:GridView>
    
        <br />
        <br />
        <br />
        <asp:GridView ID="GridView2" runat="server" AutoGenerateColumns="False" 
            Visible="False" CellPadding="4" ForeColor="#333333" GridLines="None" Width="1025px" CssClass="auto-style4" >
            <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
            <Columns>
                <asp:BoundField DataField="name" HeaderText="用户名" SortExpression="文本" />
                <asp:BoundField DataField="address" HeaderText="地址" SortExpression="文本" />
                <asp:BoundField DataField="Email" HeaderText="Email" SortExpression="文本" />
            </Columns>
            <EditRowStyle BackColor="#999999" />
            <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
            <PagerStyle BackColor="#284775" ForeColor="White" HorizontalAlign="Center" />
            <RowStyle BackColor="#F7F6F3" ForeColor="#333333" />
            <SelectedRowStyle BackColor="#E2DED6" Font-Bold="True" ForeColor="#333333" />
            <SortedAscendingCellStyle BackColor="#E9E7E2" />
            <SortedAscendingHeaderStyle BackColor="#506C8C" />
            <SortedDescendingCellStyle BackColor="#FFFDF8" />
            <SortedDescendingHeaderStyle BackColor="#6F8DAE" />
        </asp:GridView>
    
    </div>
    </form>
</body>
</html>
