<%@ Page Language="C#" AutoEventWireup="true" CodeFile="updata.aspx.cs" Inherits="updata" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>无标题页</title>
    <style type="text/css">
        .style1
        {
            text-align: center;
        }
        .style2
        {
            height: 25px;
        }
        .auto-style1 {
            height: 893px;
            background-image: url('images/55730b847cd77_1024.jpg');
        }
        .auto-style2 {
            font-family: 楷体;
            font-weight: bold;
            font-size: medium;
        }
        .auto-style3 {
            height: 25px;
            font-family: 楷体;
            font-weight: bold;
            font-size: medium;
        }
        .auto-style4 {
            text-align: center;
            font-family: 楷体;
            font-weight: bold;
            font-size: x-large;
        }
    </style>

</head>
<body>
    <form id="form1" runat="server">
    <div id ="dow" class="auto-style1">
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
    <table style="width:100%;">
        <tr>
            <td class="auto-style4" colspan="4">
                修改数据</td>
        </tr>
        <tr>
            <td class="auto-style2">
                书号</td>
            <td>
                <asp:DropDownList ID="DropNo" runat="server" AutoPostBack="True" 
                    onselectedindexchanged="DropNo_SelectedIndexChanged" 
                    DataSourceID="SqlDataSource1" DataTextField="uid" DataValueField="uid" 
                    Width="98px" CssClass="auto-style2">
                </asp:DropDownList>
            </td>
            <td class="auto-style2">
                书名</td>
            <td>
                <asp:TextBox ID="TextName" runat="server"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">
                类别</td>
            <td>
                <asp:RadioButtonList ID="RadioSex" runat="server" RepeatDirection="Horizontal">
                    <asp:ListItem Selected="True">科技类</asp:ListItem>
                    <asp:ListItem>文学类</asp:ListItem>
                </asp:RadioButtonList>
            </td>
            <td class="auto-style2">
                作者</td>
            <td>
                <asp:TextBox ID="TextClass" runat="server"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style3">
                出版社</td>
            <td class="style2">
                <asp:TextBox ID="TextMath" runat="server" CssClass="auto-style2"></asp:TextBox>
            </td>
            <td class="auto-style3">
                价格</td>
            <td class="style2">
                <asp:TextBox ID="TextChs" runat="server"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">
                &nbsp;</td>
            <td class="auto-style2">
                &nbsp;</td>
            <td class="auto-style2">
                &nbsp;</td>
            <td>
                &nbsp;</td>
        </tr>
        <tr>
            <td colspan="2">
                <asp:Button ID="ButtonSubmit" runat="server" onclick="ButtonSubmit_Click" 
                    Text="提交" style="width: 40px" CssClass="auto-style2" />
            </td>
            <td colspan="2">
                <asp:Button ID="ButtonBack" runat="server" onclick="ButtonBack_Click" 
                    Text="返回" CssClass="auto-style2" />
            </td>
        </tr>
    </table>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:App_DataConnectionString %>" SelectCommand="SELECT [uid] FROM [grade]"></asp:SqlDataSource>
    </div>
    </form>
</body>
</html>
