using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using System .Data;

public partial class User : System.Web.UI.Page
{

    protected void Page_Load(object sender, EventArgs e)
    {
        Label1.Text = "你好," + (string)Session["pass"];
        if (!IsPostBack)
        {
            String sqlconn = "Data Source=DESKTOP-D8SO2KF;Initial Catalog=App_Data;Integrated Security=true";
            SqlConnection myconnection = new SqlConnection(sqlconn);
            SqlDataAdapter da = new SqlDataAdapter("select id from message", myconnection);
            DataSet ds = new DataSet();
            da.Fill(ds);
            DropClass.DataSource = ds.Tables[0].DefaultView;
            DropClass.DataTextField = "id";
            DropClass.DataBind();
            DropClass.Items.Add("管理员");
            myconnection.Close();
        }
    }
    protected void BuyBook_Click(object sender, EventArgs e)
    {
        Response.Redirect("curriculum.aspx?st=" + DropClass.SelectedItem.Text);

    }
    protected void DropClass_SelectedIndexChanged(object sender, EventArgs e)
    {

    }
}
