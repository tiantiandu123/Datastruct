using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Data.SqlTypes;
public partial class login_mananger : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        String sqlconn = "Data Source=DESKTOP-D8SO2KF;Initial Catalog=App_Data;Integrated Security=true";
        SqlConnection myconnection = new SqlConnection(sqlconn);
       // OleDbConnection conn = new OleDbConnection();
       // string Id = TextBox1.Text;
        //myconnection.ConnectionString = "provider=Microsoft.Jet.OleDb.4.0;" + "Data Source=" + Server.MapPath("App_Data/information.mdb");
        //string StrSel = "Select*from message where id='" + TextBox1.Text + "'and pwd='" + TextBox2.Text + "'";
        myconnection.Open();
        SqlCommand com = new SqlCommand("Select*from message where id='" + TextBox1.Text + "'and pwd='" + TextBox2.Text + "'", myconnection);
        SqlDataReader dr = com.ExecuteReader();
        dr.Read();
        if (dr.HasRows)
        {

            Session["pass"] = TextBox1.Text;
            if (TextBox1.Text == "杜甜甜")
            {
                Server.Transfer("Default.aspx");
                Response.Redirect("Default.aspx");
            }
            else
            {
                Server.Transfer("custom.aspx");
                Response.Redirect("custom.aspx");
            }
        }
        else
        {
            Response.Redirect("Index.aspx");
        }
        myconnection.Close();
    }
}