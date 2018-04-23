<%@ Page Language="C#" AutoEventWireup="true" CodeFile="add.aspx.cs" Inherits="add" %>

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
            height: 23px;
        }
        .auto-style1 {
            font-family: 楷体;
            font-weight: bold;
            font-size: medium;
        }
        .auto-style2 {
            text-align: center;
            font-family: 华文新魏;
            font-weight: bold;
            font-size: x-large;
            color: #800080;
            height: 106px;
            background-color: #CCFFFF;
        }
        .auto-style3 {
            width: 352px;
            background-color: #FFFFCC;
        }
        .auto-style4 {
            height: 23px;
            width: 352px;
            background-color: #FFFFCC;
        }
        .auto-style5 {
            width: 101%;
            position: relative;
            left: -3px;
            top: 156px;
            margin-left: 0px;
            background-color: #66FF99;
        }
        .auto-style6 {
            height: 23px;
            width: 301px;
            background-color: #FFFFCC;
        }
        .auto-style7 {
            width: 301px;
            font-family: 楷体;
            font-weight: bold;
            background-color: #FFFFCC;
        }
        .auto-style8 {
            font-family: 楷体;
            font-weight: bold;
            font-size: medium;
            width: 301px;
            background-color: #FFFFCC;
        }
        .auto-style9 {
            width: 451px;
            background-color: #FFFFCC;
        }
        .auto-style10 {
            height: 23px;
            width: 451px;
            background-color: #FFFFCC;
        }
        .auto-style11 {
            font-family: 楷体;
            font-weight: bold;
            font-size: medium;
            width: 236px;
            background-color: #FFFFCC;
        }
        .auto-style12 {
            height: 23px;
            width: 236px;
            background-color: #FFFFCC;
        }
        .auto-style13 {
            font-family: 楷体;
            font-weight: bold;
            font-size: medium;
            background-color: #FFFFCC;
        }
        .auto-style14 {
            background-color: #FFFFCC;
        }
        .auto-style15 {
            background-image: url('images/images/28164833791.jpg');
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div id="dow" class="auto-style15">
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
    <table class="auto-style5" >
        <tr>
            <td class="auto-style2" colspan="4">
                添加新纪录</td>
        </tr>
        <tr>
            <td class="auto-style11">
                书籍编号</td>
            <td class="auto-style3">
                <asp:TextBox ID="TextNo" runat="server" CssClass="auto-style1"></asp:TextBox>
            </td>
            <td class="auto-style8">
                书籍名称</td>
            <td class="auto-style9">
                <asp:TextBox ID="TextName" runat="server" CssClass="auto-style1"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style11">
                类别</td>
            <td class="auto-style3">
                <asp:RadioButtonList ID="RadioSex" runat="server" RepeatDirection="Horizontal" 
                    onselectedindexchanged="RadioSex_SelectedIndexChanged">
                    <asp:ListItem Selected="True">科技类</asp:ListItem>
                    <asp:ListItem>文学类</asp:ListItem>
                </asp:RadioButtonList>
            </td>
            <td class="auto-style7">
                作者</span></td>
            <td class="auto-style9">
                <asp:TextBox ID="TextClass" runat="server" CssClass="auto-style1"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style11">
                出版社</td>
            <td class="auto-style3">
                <asp:TextBox ID="TextMath" runat="server" ontextchanged="TextMath_TextChanged" CssClass="auto-style1"></asp:TextBox>
            </td>
            <td class="auto-style8">
                价格</td>
            <td class="auto-style9">
                <asp:TextBox ID="TextChs" runat="server" CssClass="auto-style1"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style12">
                </td>
            <td class="auto-style4">
            </td>
            <td class="auto-style6">
                </td>
            <td class="auto-style10">
                </td>
        </tr>
        <tr>
            <td colspan="2" class="auto-style14">
                <asp:Button ID="ButtonSubmit" runat="server" onclick="ButtonSubmit_Click" 
                    Text="提交" CssClass="auto-style13" />
            </td>
            <td colspan="2" class="auto-style14">
                <asp:Button ID="ButtonBack" runat="server" onclick="ButtonBack_Click" 
                    Text="返回" CssClass="auto-style13" />
            </td>
        </tr>
    </table>
    </div>
    </form>
</body>
</html>
