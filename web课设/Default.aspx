<%@ Page Language="C#"  Debug="true" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head id="Head1" runat="server">
    <title>无标题页</title>
    
    <style type="text/css">
        .auto-style2 {
            font-family: 楷体;
            font-weight: bold;
            font-size: large;
            color: #000000;
        }
        .auto-style3 {
            font-family: 华文楷体;
            font-weight: bold;
            font-size: large;
        }
        .auto-style4 {
            width: 239px;
            height: 20px;
            position: absolute;
            left: 609px;
            top: 177px;
            font-family: 楷体;
            font-weight: bold;
            font-size: xx-large;
        }
        .auto-style5 {
            font-weight: bold;
            margin-left: 192px;
            margin-top: 0px;
        }
        .auto-style6 {
            height: 150px;
            background-image: url('images/images/28164833791.jpg');
        }
        .auto-style7 {
            background-color: #C0C0C0;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div id="login" class="auto-style6">
    
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <asp:Label ID="Label1" runat="server" Text="Label" CssClass="auto-style4"></asp:Label>
    
    </div>
    <div id="left" class="auto-style7">
    
        <br />
        <br />
    
        <br />
        <br />
        <asp:GridView ID="GridView1" runat="server" 
            OnSelectedIndexChanged="GridView1_SelectedIndexChanged" Width="1113px"  
            AutoGenerateColumns="False" Height="324px" CellPadding="4" CssClass="auto-style5" ForeColor="#333333" GridLines="None">
            <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
            <Columns>
                <asp:BoundField DataField="uid" HeaderText="书籍编号" />
                <asp:BoundField DataField="uname" HeaderText="书籍名称" SortExpression="文本" ></asp:BoundField>
                <asp:BoundField DataField="usex" HeaderText="类别" SortExpression="文本" ></asp:BoundField>
                <asp:BoundField DataField="class" HeaderText="作者" SortExpression="文本" />
                <asp:BoundField DataField="math" HeaderText="出版社" SortExpression="数据" />
                <asp:BoundField DataField="chs" HeaderText="价格" SortExpression="数据" />
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
        <asp:Button ID="Button1" runat="server" Text="书籍管理" CssClass="auto-style3" />
        <br />
        <br />
        <br class="auto-style3" />
        <asp:Button ID="Button2" runat="server" PostBackUrl="~/User.aspx" Text="用户管理" CssClass="auto-style3" />
        <br />
        <br />
        <br />
        <br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:LinkButton ID="LinkIns" runat="server" OnClick="LinkIns_Click" CssClass="auto-style2">插入记录</asp:LinkButton>
        <asp:LinkButton ID="LinkUpdata" runat="server" OnClick="LinkUpdata_Click" CssClass="auto-style2">修改记录</asp:LinkButton>
        <asp:LinkButton ID="LinkDel" runat="server" OnClick="LinkDel_Click" CssClass="auto-style2">删除记录</asp:LinkButton>
        </div>
    </form>
</body>
</html>
