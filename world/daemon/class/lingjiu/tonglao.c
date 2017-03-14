// /NPC tonglao.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("��ɽͯ��", ({ "tong lao", "tong", "lao" }));
	set("long",
	    "�����ǡ����չ����Ŀ�ɽ��ʦ.\n"+
	    "էһ���ƺ��Ǹ�ʮ�߰����Ů��,������ȴ����������.\n"+
	    "˫Ŀ���,��������,��������ʱ,����һ�����˵�����.\n");
	set("title", "���չ�����");
	set("gender", "Ů��");
	set("age", 96);
	set("nickname", HIR "Ψ�Ҷ���" NOR);
	set("shen_type",0);
	set("attitude", "peaceful");
set("vendor_goods", ([
               "������":"/u/sbaa/buqidan",
                "������":"/u/sbaa/bujindan",
                "����":"/u/sbaa/busendan",
                "��������¶":"/u/sbaa/txiang",    
                "��ҩ": "/obj/drug/hurt_drug",
                "��ҩ": "/obj/drug/snake_drug",
        ]) );
	set("str", 25);
	set("int", 35);
	set("con", 40);
	set("dex", 40);

	set("kee", 5000);
	set("max_kee", 5000);
	set("gin", 4000);
	set("max_gin", 4000);
	set("force", 4000);
	set("max_force", 4000);
	set("jiali", 100);

	set("combat_exp", 2500000);
	set("score", 200000);
	set_skill("force", 200);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("hand",250);
	set_skill("strike", 250);
    set_skill("sword",150);

	set_skill("zhemei-shou",200);
	set_skill("liuyang-zhang",200);
    set_skill("tianyu-qijian",120);
	set_skill("yueying-wubu",200);
	set_skill("bahuang-gong", 250);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
    map_skill("strike","liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
    map_skill("sword","tianyu-qijian");

    prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	create_family("���չ�",1, "��ɽ��ʦ");
	
	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
}
void init()
{
	::init();
	add_action("do_vendor_list", "list");
    add_action("do_check", "check");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "qu");
	add_action("do_convert", "convert");

}
void attempt_apprentice(object ob)
{
   
   if ((string)ob->query("gender")!="Ů��")
           {
 		command("say ��������!");
		return;
	   }
   if ((int)ob->query_skill("bahuang-gong", 1) < 130) 
           {
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�");
		return;
	   }
   if (ob->query_con() < 30) 
      	   {
		command("say ���Ź�����Ϊ����,��ĸ����ƺ�����.");
		return;
	   }
   command("recruit " + ob->query("id"));
   if((string)ob->query("class") != "dancer")
     ob->set("class", "dancer");
   return;
}


int do_check()
{
	// here we use 3 units to display bank infos
	int total = (int)this_player()->query("balance");
	
	if (!total || total < 0) {
		this_player()->set("balance", 0);
		return notify_fail("���ڱ��̺�û�д�Ǯ��\n");
	}
	write("ǮС�����ĸ����㣺���ڱ��̺Ź�����" + 
		MONEY_D->money_str(total) + "\n");

	return 1;
}
int do_convert(string arg)
{
        string from, to;
        int amount, bv1, bv2;
        object from_ob, to_ob;

        if( !arg || sscanf(arg, "%d %s to %s", amount, from, to)!=3 )
                return notify_fail("ָ���ʽ��convert <����> <��������> to <����
����>\n");

        from_ob = present(from + "_money", this_player());
        to_ob = present(to + "_money", this_player());
       if (this_player()->is_busy()) return notify_fail("�𼱣���������ǮҪ��?
������\n");
        if( !to_ob && file_size("/obj/money/" + to + ".c") < 0 )
                return notify_fail("����һ���һ��Ǯ��\n");

        if( !from_ob )          return notify_fail("������û�����ֻ��ҡ�\n");
        if( amount < 1 )        return notify_fail("�һ�����һ������Ҫ�һ�һ����
\n");

        if( (int)from_ob->query_amount() < amount )
                return notify_fail("������û�������" + from_ob->query("name") +
 "��\n");

        bv1 = from_ob->query("base_value");
        if( !bv1 ) return notify_fail("���ֶ�����ֵǮ��\n");

        bv2 = to_ob ? to_ob->query("base_value") : call_other("/obj/money/" + to
, "query", "base_value" );

        if( bv1 < bv2 ) amount -= amount % (bv2 / bv1);
        if( amount==0 ) return notify_fail("��Щ" + from_ob->query("name") + "��
��ֵ̫���ˣ�������\n");          
        if( !to_ob ) {
                to_ob = new("/obj/money/" + to);
                to_ob->move(this_player());
                to_ob->set_amount(amount * bv1 / bv2);
        } else
                to_ob->add_amount(amount * bv1 / bv2);
/*	message_vision(sprintf("$N������ȡ��%s%s%s,����%s%s%s�� \n",amount,
from_ob->query("base_unit"),
from_ob->quesry("name"),amount*bv1/bv2,to_ob->query("base_unit"),to_ob->query("name")),
this_player() );
*/
        message_vision( sprintf("$N������ȡ��%s%s%s������%s%s%s��\n",
chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), 
to_ob->query("name")),
                this_player() );

        from_ob->add_amount(-amount);

        return 1;
}

int do_deposit(string arg)
{
	string what;
	int amount;
	object what_ob;

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
		return notify_fail("�����ʽ��deposit:cun <����> <���ҵ�λ>\n");
//     if (this_player()->is_busy()) return notify_fail("�𼱣���������ǮҪ���������\n");

	what_ob = present(what + "_money", this_player());
	if (!what_ob)
		return notify_fail("������û�д�����Ǯ��\n");
	if (amount < 1)
		return notify_fail("��������" + what_ob->query("name") + "��\n");
	if ((int)what_ob->query_amount() < amount)
		return notify_fail("�����" + what_ob->query("name") + "������\n");

	// deposit it
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
// if (this_player()->is_busy()) return notify_fail("�𼱣���������ǮҪ���������\n");

	
if (amount < 1)
		return notify_fail("����ȡ������Ǯ��\n");
if (amount > 100000) return notify_fail("̫����Ŀ����ȫ���������õ�ɣ�\n"); 
	if (file_size("/obj/money/" + what + ".c") < 0)
	//if ((!what="silver")||(!what="coin")||(!what="gold")||(!what="thousand-cash"))
	return notify_fail("����ȡ��ʲôǮ��\n");
	what = "/obj/money/" + what;
	if ((v = amount * what->query("base_value")) >
		this_player()->query("balance"))
		return notify_fail("����Ǯ����ȡ��\n");
//         this_player()->start_busy(1);  


	this_player()->add("balance",  -v);
	MONEY_D->pay_player(this_player(), v );
	
	message_vision(sprintf("$N��������ȡ��%s��\n", MONEY_D->money_str(v)),
		this_player());
	return 1;
}
