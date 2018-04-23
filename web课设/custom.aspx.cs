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
public partial class custom : System.Web.UI.Page
{
   
    string use;
    protected void Page_Load(object sender, EventArgs e)
    {
        Label1.Text = "你好," + (string)Session["pass"];
        use = (string)Session["pass"];
       
    }

    protected void GridView1_SelectedIndexChanged(object sender, EventArgs e)
    {
       
    }

    protected void TextBox1_TextChanged(object sender, EventArgs e)
    {
    }
    protected void Button3_Click(object sender, EventArgs e)
    {
        String sqlconn = "Data Source=DESKTOP-D8SO2KF;Initial Catalog=App_Data;Integrated Security=true";
        SqlConnection myconnection = new SqlConnection(sqlconn);
       
        string Val = "'" + use + "','" + TextBox1.Text + "','" + TextBox2.Text + "','" + TextBox3.Text +
            "','" + TextBox4.Text + "','" + TextBox5.Text + "'," + int.Parse(TextBox6.Text);
       // string SqlIns = "insert into buy(用户id,书号,书名,类别,作者,出版社,价格) values(" + Val + ")";
        SqlCommand mycommand = new SqlCommand("insert into buy(用户id,书号,书名,类别,作者,出版社,价格) values(" + Val + ")", myconnection);
        SqlDataAdapter da = new SqlDataAdapter();
      
        myconnection.Open();
        da.InsertCommand = mycommand;
        da.InsertCommand.ExecuteNonQuery();
        myconnection.Close();
       Label2.Visible = true;

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        Response.Redirect("Default2.aspx");
    }
}
