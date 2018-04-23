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

public partial class curriculum : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Request.QueryString["st"] == null)
        {
            Response.Redirect("Default.aspx");
        }
        this.Title = Request.QueryString["st"] + "的订单";
            //OleDbConnection conn = new OleDbConnection();
            //conn.ConnectionString = "Provider=Microsoft.Jet.OleDb.4.0;" + "Data Source=" +
            //                       Server.MapPath("App_Data/user.mdb");
            //string StrSel = "select 书名,作者,类别,出版社,价格 from buy where 用户id='" + Request.QueryString["st"] + "'" ;
            //OleDbDataAdapter da = new OleDbDataAdapter(StrSel, conn);
            //DataTable dt = new DataTable();
        String sqlconn = "Data Source=DESKTOP-D8SO2KF;Initial Catalog=App_Data;Integrated Security=true";
        SqlConnection myconnection = new SqlConnection(sqlconn);
        //myconnection.Open();
        SqlDataAdapter da = new SqlDataAdapter("select 书名,作者,类别,出版社,价格 from buy where 用户id='" + Request.QueryString["st"] + "'", myconnection);
        DataTable dt = new DataTable();
        //dr.InsertCommand.ExecuteNonQuery();
       // myconnection.Close();
            da.Fill(dt);
            GridView1.DataSource = dt;
            GridView1.DataBind();
            GridView1.Caption = "<b>" + Request.QueryString["st"] + "的订单</b>";
            GridView1.Width = 300;
            myconnection.Close();
    }
    protected void GridView1_SelectedIndexChanged(object sender, EventArgs e)
    {

    }
    protected void GridView2_SelectedIndexChanged(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        GridView2.Visible = true;
    
        String sqlconn = "Data Source=DESKTOP-D8SO2KF;Initial Catalog=App_Data;Integrated Security=true";
        SqlConnection myconnection = new SqlConnection(sqlconn);
       //myconnection.ConnectionString = "Provider=Microsoft.Jet.OleDb.4.0;" + "Data Source=" +
       //                        Server.MapPath("App_Data/information.mdb");
       // string StrSel = "select name,address,Email from message where id='" + Request.QueryString["st"] + "'";
        SqlDataAdapter da = new SqlDataAdapter("select name,address,Email from message where id='" + Request.QueryString["st"] + "'", myconnection);
        DataTable dt = new DataTable();
        da.Fill(dt);
        GridView2.DataSource = dt;
        GridView2.DataBind();
        GridView2.Caption = "<b>" + Request.QueryString["st"] + "的信息</b>";
        GridView2.Width = 300;
        myconnection.Close();
    }
}

    