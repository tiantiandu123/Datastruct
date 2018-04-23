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

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        this.Title = "DataAdaper 对象使用示例";
        Label1.Text = "你好," + (string)Session["pass"];
        LinkIns.Text = "插入记录";
        LinkDel.Text = "删除记录";
        LinkUpdata.Text = "修改数据";
        String sqlconn = "Data Source=DESKTOP-D8SO2KF;Initial Catalog=App_Data;Integrated Security=true";
        SqlConnection myconnection = new SqlConnection(sqlconn);
        SqlDataAdapter da = new SqlDataAdapter("select * from grade order by uid", myconnection);
        DataTable dt = new DataTable();
        da.Fill(dt);
        GridView1.DataSource = dt;
        GridView1.DataBind();
        GridView1.Caption = "<b>本店数目</b>";
        GridView1.Width = 300;
        myconnection .Close();
    }
    protected void GridView1_SelectedIndexChanged(object sender, EventArgs e)
    {

    }
    protected void LinkIns_Click(object sender, EventArgs e)
    {
        Response.Redirect("add.aspx");
    }
    protected void LinkUpdata_Click(object sender, EventArgs e)
    {
        Response.Redirect("updata.aspx");
    }
    protected void LinkDel_Click(object sender, EventArgs e)
    {
        Response.Redirect("del.aspx");
    }
}
