using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Data.SqlTypes;

public partial class add : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        this.Title = "添加新纪录";
        TextNo.Focus();
    }
    protected void ButtonSubmit_Click(object sender, EventArgs e)
    {
        String sqlconn = "Data Source=DESKTOP-D8SO2KF;Initial Catalog=App_Data;Integrated Security=true";
        SqlConnection myconnection = new SqlConnection(sqlconn);
      
        string Val = "'" + TextNo.Text + "','" + TextName.Text + "','" + RadioSex.SelectedValue.ToString() +
           "','" + TextClass.Text + "','" + TextMath.Text + "'," + int.Parse(TextChs.Text);
       
        myconnection.Open();
        SqlCommand mycommand = new SqlCommand("insert into grade(uid,uname,usex,class,math,chs) values(" + Val + ")", myconnection);
        SqlDataAdapter dr = new SqlDataAdapter();
        dr.InsertCommand = mycommand;
        dr.InsertCommand.ExecuteNonQuery();
        myconnection.Close();
        Response.Write("<script language= javascript>alert('新纪录添加成功，请单击“返回”回到主页面！');</script>");

    }
    protected void ButtonBack_Click(object sender, EventArgs e)
    {
        Response.Redirect("Default.aspx");
    }
    protected void RadioSex_SelectedIndexChanged(object sender, EventArgs e)
    {

    }
    protected void TextMath_TextChanged(object sender, EventArgs e)
    {

    }
}
