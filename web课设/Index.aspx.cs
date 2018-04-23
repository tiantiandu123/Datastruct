using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Data.SqlTypes;

public partial class Index : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        String sqlconn = "Data Source=DESKTOP-D8SO2KF;Initial Catalog=App_Data;Integrated Security=true";
        SqlConnection myconnection = new SqlConnection(sqlconn);
        string Id = TextBox1.Text;
        
        //string StrSel = "Select*from message where id='" + TextBox1.Text + "'and pwd='" + TextBox2.Text + "'";
        myconnection.Open();
        SqlCommand mycommand = new SqlCommand("Select*from message where id='" + TextBox1.Text + "'and pwd='" + TextBox2.Text + "'", myconnection);
        SqlDataReader dr = mycommand.ExecuteReader();
        dr.Read();
        if (dr.HasRows)
        {

            Session["pass"] = TextBox1.Text;
            if (TextBox1.Text == "Admin" || TextBox1.Text == "jiangchuang"|| TextBox1.Text == "linxiangqian"||TextBox1.Text == "林杨")
            {
                Server.Transfer("custom.aspx");
                Response.Redirect("custom.aspx");
            }
            else
                return;
           
        }
        else
        {
            Response.Redirect("Index.aspx");
        }
        myconnection.Close();
    }
    protected void ImageButton4_Click(object sender, ImageClickEventArgs e)
    {

    }
}
