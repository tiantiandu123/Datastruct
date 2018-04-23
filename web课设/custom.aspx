<%@ Page Language="C#" AutoEventWireup="true" CodeFile="custom.aspx.cs" Inherits="custom" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>无标题页</title>

    <style type="text/css">
        .style1
        {
            width: 100%;
        }
        .auto-style1 {
            height: 280px;
            background-image: url('images/images/14e037de-837b-415f-9bd3-5f7b4767ad0c.jpg');
        }
        .auto-style2 {
            width: 100%;
            background-color: #FFFFFF;
        }
        .auto-style3 {
            margin-left: 189px;
            margin-top: 0px;
        }
        .auto-style4 {
            margin-left: 0px;
        }
        .auto-style5 {
            font-family: 华文新魏;
            font-weight: bold;
            font-size: medium;
            margin-left: 364px;
        }
        .auto-style6 {
            width: 322px;
            font-family: 楷体;
            font-weight: bold;
            font-size: large;
        }
        .auto-style7 {
            font-family: 楷体;
            font-weight: bold;
            font-size: large;
        }
        .auto-style8 {
            font-family: 楷体;
            font-weight: bold;
            font-size: xx-large;
            background-image: url('images/images/14e037de-837b-415f-9bd3-5f7b4767ad0c.jpg');
        }
        .auto-style9 {
            background-image: url('images/images/8952533_201340475000_2.jpg');
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div id ="login" class="auto-style1">
    
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    
        <asp:Label ID="Label1" runat="server" Text="Label" CssClass="auto-style8"></asp:Label>
    
    </div>
    <div id="ileft">
        <br />
        <br />
        <asp:Button ID="Button1" runat="server" Text="订单查看" onclick="Button1_Click" CssClass="auto-style7" />
        <asp:GridView ID="GridView1" runat="server" AllowPaging="True" 
            DataSourceID="SqlDataSource1"
             onselectedindexchanged="GridView1_SelectedIndexChanged" CellPadding="4" CssClass="auto-style3" ForeColor="#333333" GridLines="None" Height="280px" Width="1204px">
            <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
            <Columns>
                <asp:BoundField DataField="uid" HeaderText="书号" 
                    SortExpression="uid" ReadOnly="True" />
                <asp:BoundField DataField="uname" HeaderText="书名" SortExpression="uname" />
                <asp:BoundField DataField="usex" HeaderText="类别" SortExpression="usex" />
                <asp:BoundField DataField="class" HeaderText="作者" SortExpression="class" />
                <asp:BoundField DataField="math" HeaderText="出版社" SortExpression="math" />
                <asp:BoundField DataField="chs" HeaderText="价格" SortExpression="chs" />
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
        <br class="auto-style7" />
        <br class="auto-style7" />
        <asp:Button ID="Button2" runat="server" Text="图书订购" CssClass="auto-style7" />
    </div>
    <div id="iright" >
        <br />
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:App_DataConnectionString %>" DeleteCommand="DELETE FROM [grade] WHERE [uid] = @uid" InsertCommand="INSERT INTO [grade] ([uid], [uname], [usex], [class], [math], [chs]) VALUES (@uid, @uname, @usex, @class, @math, @chs)" SelectCommand="SELECT * FROM [grade]" UpdateCommand="UPDATE [grade] SET [uname] = @uname, [usex] = @usex, [class] = @class, [math] = @math, [chs] = @chs WHERE [uid] = @uid">
            <DeleteParameters>
                <asp:Parameter Name="uid" Type="String" />
            </DeleteParameters>
            <InsertParameters>
                <asp:Parameter Name="uid" Type="String" />
                <asp:Parameter Name="uname" Type="String" />
                <asp:Parameter Name="usex" Type="String" />
                <asp:Parameter Name="class" Type="String" />
                <asp:Parameter Name="math" Type="String" />
                <asp:Parameter Name="chs" Type="String" />
            </InsertParameters>
            <UpdateParameters>
                <asp:Parameter Name="uname" Type="String" />
                <asp:Parameter Name="usex" Type="String" />
                <asp:Parameter Name="class" Type="String" />
                <asp:Parameter Name="math" Type="String" />
                <asp:Parameter Name="chs" Type="String" />
                <asp:Parameter Name="uid" Type="String" />
            </UpdateParameters>
        </asp:SqlDataSource>
        <br class="auto-style9" />
        <table class="auto-style2">
            <tr>
                <td class="auto-style6">
                    &nbsp;&nbsp;&nbsp;
                    请输入您所订购的图书号</td>
                <td>
                    <asp:TextBox ID="TextBox1" runat="server" ontextchanged="TextBox1_TextChanged" CssClass="auto-style4"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style6">
                    &nbsp;&nbsp;&nbsp;
                    请输入您所订购的图书名</td>
                <td>
                    <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style6">
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    类别</td>
                <td>
                    <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style6">
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    作者</td>
                <td>
                    <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style6">
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    出版社</td>
                <td>
                    <asp:TextBox ID="TextBox5" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style6">
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    价格</td>
                <td>
                    <asp:TextBox ID="TextBox6" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td colspan="2">
                    <br />
                    <asp:Button ID="Button3" runat="server" onclick="Button3_Click" Text="提交" CssClass="auto-style5" Width="126px" />
                    <asp:Label ID="Label2" runat="server" Text="提交成功" Visible="False"></asp:Label>
                </td>
            </tr>
        </table>
    </div>
    </form>
</body>
</html>
