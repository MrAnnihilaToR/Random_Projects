namespace My_Calculator
{
    public partial class Form1 : Form
    {
        Double resultValue = 0;
        String operationPerformed = "";
        bool isOperationPerformed = false;

        public Form1()
        {
            InitializeComponent();
        }

        private void button_click(object sender, EventArgs e)
        {
            if((textBox_result.Text == "0") || (isOperationPerformed) )
            {
                textBox_result.Clear();
            }

            isOperationPerformed = false; //// pri natiskane na butonite da e false tazi promenliva

            Button button = (Button)sender;

            if (button.Text == ".")
            {
                if (!textBox_result.Text.Contains("."))
                    textBox_result.Text = textBox_result.Text + button.Text;

            }
            else
                textBox_result.Text = textBox_result.Text + button.Text;
        }

        private void operator_click(object sender, EventArgs e)
        {
            Button button = (Button)sender;

            if (resultValue != 0)
            {
                button_equals.PerformClick();
                operationPerformed = button.Text;
                label_Operation.Text = resultValue + " " + operationPerformed;
                isOperationPerformed = true;
            }
            else
            {

                operationPerformed = button.Text;
                resultValue = Double.Parse(textBox_result.Text);
                label_Operation.Text = resultValue + " " + operationPerformed;
                isOperationPerformed = true;
            }
           
        }

        private void button_clear_entry_Click(object sender, EventArgs e)
        {
            textBox_result.Text = "0";
           // resultValue = 0;
        }

        private void button_clear_Click(object sender, EventArgs e)
        {
            textBox_result.Text = "0";
            label_Operation.Text = "";
            resultValue = 0;
        }

        private void button_equals_Click(object sender, EventArgs e)
        {
            switch (operationPerformed)
            {
                case "+":
                    textBox_result.Text = (resultValue + Double.Parse(textBox_result.Text)).ToString();
                    break;
                case "-":
                    textBox_result.Text = (resultValue - Double.Parse(textBox_result.Text)).ToString();
                    break;
                case "*":
                    textBox_result.Text = (resultValue * Double.Parse(textBox_result.Text)).ToString();
                    break;
                case "/":
                    textBox_result.Text = (resultValue / Double.Parse(textBox_result.Text)).ToString();
                    break;
            }
            resultValue = Double.Parse(textBox_result.Text);
            label_Operation.Text = "";
        }
    }
}