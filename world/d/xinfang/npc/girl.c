// roomgirl.c ����С��
// by ������
inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("����С��", ({ "girl" }));
	set("long", "һλ���û�֦��չ��С�㣡\n");
	set("gender", "Ů��");
	set("age", 20);
	set_skill("literate", 100);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	set("combat_exp", 400000);
//	set("shen_type", 1);
	setup();
	set("chat_chance", 5);
	set("chat_msg", ({
		"����С��˵���������򷿵İɣ���������ķ���������⡣\n"
		"����С��΢΢һЦ���������ߵ���\n",
		"����С����˵Ŀ�����һ�ۣ�\n",
			}) );
}
void init()
{
}
int accept_object(object who, object ob)
{       if (this_player()->query("age")<18) 
        {      write("��̫С����Щ���������򷿰ɣ�\n");
               return 0;
        } 
        if (!undefinedp(this_player()->query("myroom")))
        {     write("����С�㲻���˵�����Ѿ��������ѽ��\n");
              return 0;
        }
	if (ob->query("money_id") && ob->value() >= 1000000) {
		message_vision("����С����˵Ķ�$N˵���ðɣ��뵽��԰���������������·��ɡ�\n", this_player());
	        this_player()->set("myroom/time",time());
		return 1;
	}
}
