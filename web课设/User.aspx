<%@ Page Language="C#" AutoEventWireup="true" CodeFile="User.aspx.cs" Inherits="User" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>无标题页</title>

    <style type="text/css">
        .auto-style1 {
            text-align: center;
        }
        .auto-style2 {
            background-image: url('images/images/8952533_201340475000_2.jpg');
        }
        .auto-style3 {
            height: 176px;
        }
        .auto-style4 {
            font-family: 楷体;
            font-size: large;
            font-weight: bold;
        }
        .auto-style7 {
            font-family: 华文楷体;
            font-weight: bold;
            font-size: xx-large;
        }
        .auto-style9 {
            font-family: 楷体;
            font-size: large;
            color: #000000;
        }
        .auto-style10 {
            font-family: 楷体;
            color: #000000;
            font-weight: bold;
        }
        .auto-style11 {
            font-family: 楷体;
            font-size: large;
            color: #000000;
            font-weight: bold;
        }
        .auto-style12 {
            font-family: 楷体;
            font-size: large;
            font-weight: bold;
            margin-left: 174px;
        }
    </style>

</head>
<body style="height: 1044px">
    <form id="form1" runat="server" class="auto-style2">
    <div id="login">
    
        <p class="auto-style1">
    
        <asp:Label ID="Label1" runat="server" Text="Label" CssClass="auto-style7"></asp:Label>
    
        </p>
    
    </div>
    <div id="left">
    
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
    
    &nbsp;&nbsp;
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
        <br />
        <span class="auto-style9">&nbsp;</span><asp:Button ID="Button1" runat="server" CausesValidation="False" 
            PostBackUrl="~/Default.aspx" Text="书籍管理" CssClass="auto-style12" Width="255px" />
    
        <br />
    
    </div>
    <div id="right" class="auto-style3">
        <p class="auto-style1">
            <span class="auto-style11">&nbsp;&nbsp;&nbsp;&nbsp; 请选择一个用户</span><asp:DropDownList ID="DropClass" 
            runat="server" onselectedindexchanged="DropClass_SelectedIndexChanged" CssClass="auto-style4">
        </asp:DropDownList>
            <span class="auto-style11">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><asp:Button ID="BuyBook" runat="server" 
            onclick="BuyBook_Click" Text="查看订单" CssClass="auto-style4" />
    
            <span class="auto-style10">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span>
        </p>
       
    
    </div>
    </form>
</body>
</html>
