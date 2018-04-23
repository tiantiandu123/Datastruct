using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using System.Data;
public partial class Default2 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        this.Title = (string)Session["pass"] + "的订单";
        String sqlconn = "Data Source=DESKTOP-D8SO2KF;Initial Catalog=App_Data;Integrated Security=true";
        SqlConnection myconnection = new SqlConnection(sqlconn);
        string StrSel = "select 书名,作者,类别,出版社,价格 from buy where 用户id='" + (string)Session["pass"] + "'";
       // OleDbDataAdapter da = new OleDbDataAdapter(StrSel, conn);
        SqlDataAdapter da = new SqlDataAdapter("select 书名,作者,类别,出版社,价格 from buy where 用户id='" + (string)Session["pass"] + "'", myconnection);
        DataTable dt = new DataTable();
        da.Fill(dt);
        GridView1.DataSource = dt;
        GridView1.DataBind();
        GridView1.Caption = "<b>" +(string)Session["pass"] + "的订单</b>";
        GridView1.Width = 300;
        myconnection.Close();
    }
    protected void GridView1_SelectedIndexChanged(object sender, EventArgs e)
    {

    }
}
