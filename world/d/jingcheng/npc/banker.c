// banker.c
// changed by dwolf

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�����", ({"xiang guofu", "xiang" }));
	set("title", MAG"Ǯׯ�ϰ�"NOR);
	set("nickname", YEL"��������"NOR);
	set("gender", "����"); 

	set("long", 
	"�������С�̳г���ҵ��������ң�����ӣ������˰��������ӣ������ĵػ���ͦ�õġ�\n");    
	set("age", 35);
	set("str", 26);
	set("int", 30);
	set("kar", 25);
	set("con", 24);

	set("kee", 600); 
	set("max_kee", 600);
	set("gin", 200);
	set("max_gin", 200);

	set("combat_exp", 100000);
	set("attitude", "peacful");
	set("env/wimpy", 50);
	set("chat_chance", 5);
	set("chat_msg", ({
	YEL"�������ȻһЦ����Ǯׯ���ж��ٶ�����ʷ������׿�����㾡�ܷ��ġ�\n"NOR,
	YEL"�����������˵�����ڱ����Ǯȡʮ��֮һ����Ϣ�������Ѿ����ˣ����������Ű�ɡ�\n"NOR,   
	HIW"�������Ȼ̾��һ����:ʲôʱ����Ҳ�������һ��ȥ�ݺὭ������������Ǹö�ð���\n"NOR,
	}));

	set_skill("unarmed", 70);
	set_skill("dodge", 70); 
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);

	setup();
	add_money("gold", 1);
}
void init()
{
        add_action("do_check", "check");
        add_action("do_check", "chazhang");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
}

int do_check()
{
        // here we use 3 units to display bank infos
        int total = (int)this_player()->query("balance");

        if (!total || total < 0) {
                this_player()->set("balance", 0);
                return notify_fail("���ڱ��̺�û�д�Ǯ��\n");
        }                                                             
        write("��������ĸ����㣺���ڱ��̺Ź�����" +
                MONEY_D->money_str(total) + "\n");

        return 1;
}                                         
int do_deposit(string arg)
{
        string what;
        int amount;
        object what_ob;

        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
                return notify_fail("�����ʽ��deposit:cun <����> <���ҵ�λ>\n");
     if (this_player()->is_busy()) return notify_fail("�𼱣���������ǮҪ����
�����\n");

        what_ob = present(what + "_money", this_player());
        if (!what_ob)
                return notify_fail("������û�д�����Ǯ��\n");
        if (amount < 1)
                return notify_fail("��������" + what_ob->query("name") + "��\n
");
        if ((int)what_ob->query_amount() < amount)
                return notify_fail("�����" + what_ob->query("name") + "������\n
");
                            
        this_player()->add("balance", what_ob->query("base_value") * amount);
//        this_player()->start_busy(1);
        what_ob->add_amount(-amount);
        message_vision(sprintf("$N�ó�%s%s%s����������š�\n",
        chinese_number(amount), what_ob->query("base_unit"),
        what_ob->query("name")), this_player());

        return 1;
}

int do_withdraw(string arg)
{
        int amount, v;
        string what;

        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
                return notify_fail("�����ʽ��withdraw|qu <����> <���ҵ�λ>\n");
 if (this_player()->is_busy()) return notify_fail("�𼱣���������ǮҪ��������
�\n");


if (amount < 1)                
                return notify_fail("����ȡ������Ǯ��\n");
if (amount > 100000) return notify_fail("̫����Ŀ����ȫ���������õ�ɣ�\n");
        if (file_size("/obj/money/" + what + ".c") < 0)
        if ((!what="silver")||(!what="coin")||(!what="gold")||(!what="thousand
-cash"))
        return notify_fail("����ȡ��ʲôǮ��\n");
        what = "/obj/money/" + what;
        if ((v = amount * what->query("base_value")) >
                this_player()->query("balance"))
                return notify_fail("����Ǯ����ȡ��\n");

        this_player()->add("balance",  -v);
        MONEY_D->pay_player(this_player(), v );
        message_vision(sprintf("$N��������ȡ��%s��\n", MONEY_D->money_str(v)),
                this_player());
        return 1;
}                           

