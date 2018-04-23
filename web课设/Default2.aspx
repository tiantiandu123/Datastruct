<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default2.aspx.cs" Inherits="Default2" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>无标题页</title>
   
    <style type="text/css">
        .auto-style1 {
            font-family: 楷体;
            font-weight: bold;
            font-size: large;
            margin-left: 444px;
        }
        .auto-style2 {
            width: 788px;
            height: 120px;
            position: absolute;
            top: 140px;
            left: 115px;
            z-index: 1;
            margin-left: 105px;
        }
        .auto-style3 {
            text-align: center;
        }
    </style>
   
</head>
<body>
    <form id="form1" runat="server">
    <div id="ileft">
        <br />
        <asp:Button ID="Button1" runat="server" PostBackUrl="~/custom.aspx" 
            Text="图书订购" CssClass="auto-style1" Width="238px" />
        <br />
        <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <br />
&nbsp;&nbsp;&nbsp;&nbsp;
        <br />
    </div>
    <div id="iright">
    
        <p class="auto-style3">
    
        <asp:GridView ID="GridView1" runat="server" 
            onselectedindexchanged="GridView1_SelectedIndexChanged" CellPadding="4" CssClass="auto-style2" ForeColor="#333333" GridLines="None" Width="788px">
            <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
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
    
        </p>
    
    </div>
    </form>
</body>
</html>
