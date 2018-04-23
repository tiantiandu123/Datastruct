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
public partial class updata : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        this.Title = "更新记录";
        DropNo.AutoPostBack = true;
        if (!IsPostBack)
        {
            String sqlconn = "Data Source=DESKTOP-D8SO2KF;Initial Catalog=App_Data;Integrated Security=true";
            SqlConnection myconnection = new SqlConnection(sqlconn);
            string SqlStr = "select *from grade";
            SqlDataAdapter da = new SqlDataAdapter("select *from grade", myconnection);
            DataTable dt = new DataTable();
            da.Fill(dt);
            DataRow MyRow = dt.Rows[0];
            TextName.Text = MyRow["uname"].ToString();
            if (MyRow["usex"].ToString() == "男")
            {
                RadioSex.SelectedIndex = 0;
            }
            else
            {
                RadioSex.SelectedIndex = 1;
            }
            TextClass.Text = MyRow["class"].ToString();
            TextMath.Text = MyRow["math"].ToString();
            TextChs.Text = MyRow["chs"].ToString();
            myconnection.Close();
        }
    }

    protected void  ButtonSubmit_Click(object sender, EventArgs e)
    {
        
        String sqlconn = "Data Source=DESKTOP-D8SO2KF;Initial Catalog=App_Data;Integrated Security=true";
        SqlConnection myconnection = new SqlConnection(sqlconn);
    string SqlStr = "select *from grade where uid='" + DropNo.Text + "'";
    SqlDataAdapter da = new SqlDataAdapter(SqlStr, myconnection);
        DataTable dt = new DataTable();
    
        SqlCommandBuilder builder = new SqlCommandBuilder(da);
        da.Fill(dt);
        DataRow MyRow = dt.Rows[0];
        MyRow[1] = TextName.Text;
        MyRow[2] = RadioSex.SelectedValue.ToString();
        MyRow[3] = TextClass.Text;
        MyRow[4] = TextMath.Text;
        MyRow[5] = int.Parse(TextChs.Text);
        da.Update(dt);
       
        Response.Write("<script language= javascript>alert('纪录更新成功，请单击“返回”回到主页面！');</script>");
        myconnection.Close();
     }
     
    protected void  ButtonBack_Click(object sender, EventArgs e)
     {
     Response.Redirect("default.aspx");
     }
    
    protected void DropNo_SelectedIndexChanged(object sender, EventArgs e)
     {
       
         String sqlconn = "Data Source=DESKTOP-D8SO2KF;Initial Catalog=App_Data;Integrated Security=true";
         SqlConnection myconnection = new SqlConnection(sqlconn);
     string SqlStr = "select * from grade where uid=" + DropNo.Text + "'";
     SqlDataAdapter da = new SqlDataAdapter("select * from grade where uid='" + DropNo.Text + "'", myconnection);
     DataTable dt = new DataTable();
     da.Fill(dt);
     DataRow MyRow = dt.Rows[0];
     TextName.Text = MyRow["uname"].ToString();
     if (MyRow["usex"].ToString() == "男")
     {
        RadioSex.SelectedIndex = 0;
     }
     else
     {
        RadioSex.SelectedIndex = 1;
     }
     TextClass.Text = MyRow["class"].ToString();
     TextMath.Text = MyRow["math"].ToString();
     TextChs.Text = MyRow["chs"].ToString();
     myconnection.Close();
    }
}
