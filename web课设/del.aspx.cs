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
public partial class del : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            this.Title = "删除记录";
            LabelMsg.Text = "单击“确定”将删除当前记录";
            String sqlconn = "Data Source=DESKTOP-D8SO2KF;Initial Catalog=App_Data;Integrated Security=true";
            SqlConnection myconnection = new SqlConnection(sqlconn);
            string SqlStr = "select top 1 * from grade";
            //OleDbDataAdapter da = new OleDbDataAdapter(SqlStr, conn);
            SqlDataAdapter da = new SqlDataAdapter("select top 1 * from grade", myconnection);
            DataTable dt = new DataTable();
            da.Fill(dt);
            GridView1.DataSource = dt;
            GridView1.DataBind();
            myconnection.Close();
        }
    }

    protected void ButtonOK_Click(object sender, EventArgs e)
    {
        String sqlconn = "Data Source=DESKTOP-D8SO2KF;Initial Catalog=App_Data;Integrated Security=true";
        SqlConnection myconnection = new SqlConnection(sqlconn);
        string SqlDel = "delete from grade where uid='" + DropNo.SelectedItem.Text + "'";
        SqlCommand DelCom = new SqlCommand("delete from grade where uid='" + DropNo.SelectedItem.Text + "'", myconnection);
        SqlDataAdapter da = new SqlDataAdapter();
        myconnection.Open();
        da.DeleteCommand = DelCom;
        da.DeleteCommand.ExecuteNonQuery();
        myconnection.Close();
        Label1.Visible = true;
    }
  
protected void  DropNo_SelectedIndexChanged(object sender, EventArgs e)
{

    String sqlconn = "Data Source=DESKTOP-D8SO2KF;Initial Catalog=App_Data;Integrated Security=true";
    SqlConnection myconnection = new SqlConnection(sqlconn);
        string SqlStr = "select *from grade where uid='" + DropNo.Text + "'";
        SqlDataAdapter da = new SqlDataAdapter("select *from grade where uid='" + DropNo.Text + "'", myconnection);
        DataTable dt = new DataTable();
        da.Fill(dt);
        GridView1.DataSource = dt;
        GridView1.DataBind();
        myconnection.Close();
}
protected void  ButtonBack_Click(object sender, EventArgs e)
{
     Response.Redirect("Default.aspx");
}

}