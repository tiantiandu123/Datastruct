<%@ Page Language="C#" AutoEventWireup="true" CodeFile="del.aspx.cs" Inherits="del" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>无标题页</title>
    <style type="text/css">
        .style1
        {
            text-align: center;
        }
        .auto-style1 {
            font-family: 楷体;
            font-weight: bold;
            font-size: large;
        }
        .auto-style2 {
            font-family: 华文仿宋;
            font-weight: bold;
            font-size: large;
        }
        .auto-style3 {
            width: 318px;
        }
        .auto-style4 {
            width: 529px;
        }
        .auto-style5 {
            font-family: 华文仿宋;
            font-weight: bold;
            font-size: large;
            margin-left: 0px;
        }
        .auto-style6 {
            width: 100%;
            height: 809px;
            background-image: url('images/61.jpg');
        }
        .auto-style7 {
            background-image: url('images/61.jpg');
        }
    </style>
    
</head>
<body>
    <form id="form1" runat="server">
    <div id ="dow" class="auto-style7">
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
    <table class="auto-style6">
        <tr>
            <td class="style1" colspan="3">
                <span class="auto-style2">选择要删除的书号</span><asp:DropDownList ID="DropNo" runat="server" AutoPostBack="True" 
                   DataTextField="uid" DataValueField="uid" 
                    onselectedindexchanged="DropNo_SelectedIndexChanged" 
                    DataSourceID="SqlDataSource1" CssClass="auto-style5">
                </asp:DropDownList>
            </td>
        </tr>
        <tr>
            <td colspan="3">
                <asp:GridView ID="GridView1" runat="server" AllowSorting="True" 
                    AutoGenerateColumns="False" DataKeyNames="uid" BackColor="LightGoldenrodYellow" BorderColor="Tan" BorderWidth="1px" CellPadding="2" ForeColor="Black" GridLines="None" Width="1147px" >
                    <AlternatingRowStyle BackColor="PaleGoldenrod" />
                    <Columns>
                        <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" />
                        <asp:BoundField DataField="uid" HeaderText="uid" ReadOnly="True" 
                            SortExpression="uid" />
                        <asp:BoundField DataField="uname" HeaderText="uname" SortExpression="uname" />
                        <asp:BoundField DataField="usex" HeaderText="usex" SortExpression="usex" />
                        <asp:BoundField DataField="class" HeaderText="class" SortExpression="class" />
                        <asp:BoundField DataField="math" HeaderText="math" SortExpression="math" />
                        <asp:BoundField DataField="chs" HeaderText="chs" SortExpression="chs" />
                    </Columns>
                    <FooterStyle BackColor="Tan" />
                    <HeaderStyle BackColor="Tan" Font-Bold="True" />
                    <PagerStyle BackColor="PaleGoldenrod" ForeColor="DarkSlateBlue" HorizontalAlign="Center" />
                    <SelectedRowStyle BackColor="DarkSlateBlue" ForeColor="GhostWhite" />
                    <SortedAscendingCellStyle BackColor="#FAFAE7" />
                    <SortedAscendingHeaderStyle BackColor="#DAC09E" />
                    <SortedDescendingCellStyle BackColor="#E1DB9C" />
                    <SortedDescendingHeaderStyle BackColor="#C2A47B" />
                </asp:GridView>
            </td>
        </tr>
        <tr>
            <td class="auto-style3">
                <asp:Label ID="LabelMsg" runat="server" CssClass="auto-style1"></asp:Label>
            </td>
            <td class="auto-style4">
                <asp:Button ID="ButtonOK" runat="server" onclick="ButtonOK_Click" Text="确定" CssClass="auto-style1" />
                <asp:Label ID="Label1" runat="server" Font-Bold="True" Text="删除成功" 
                    Visible="False" CssClass="auto-style1"></asp:Label>
            </td>
            <td>
                <asp:Button ID="ButtonBack" runat="server" Text="返回" 
                    onclick="ButtonBack_Click" CssClass="auto-style1" />
            </td>
        </tr>
    </table>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:App_DataConnectionString %>" DeleteCommand="DELETE FROM [grade] WHERE [uid] = @uid" InsertCommand="INSERT INTO [grade] ([uid]) VALUES (@uid)" SelectCommand="SELECT [uid] FROM [grade]">
            <DeleteParameters>
                <asp:Parameter Name="uid" Type="String" />
            </DeleteParameters>
            <InsertParameters>
                <asp:Parameter Name="uid" Type="String" />
            </InsertParameters>
        </asp:SqlDataSource>
        <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:App_DataConnectionString %>" DeleteCommand="DELETE FROM [grade] WHERE [uid] = @uid" InsertCommand="INSERT INTO [grade] ([uid]) VALUES (@uid)" SelectCommand="SELECT [uid] FROM [grade]">
            <DeleteParameters>
                <asp:Parameter Name="uid" Type="String" />
            </DeleteParameters>
            <InsertParameters>
                <asp:Parameter Name="uid" Type="String" />
            </InsertParameters>
        </asp:SqlDataSource>
    </div>
    </form>
</body>
</html>
