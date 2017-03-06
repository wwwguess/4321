// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;

void create()
{
	set_name("����»", ({ "rong youlu", "rong" , "youlu" }));
	set("title",RED"�����ϰ�"NOR);
	set("long",
	"�ټ����̵��ϰ壬���û�������������������������ѧ��һ���书����Ϊ����ʵ��\n"
	"�Դ������̿�������������û�������̽��������£����������������������\n");
	set("gender", "����");
	set("age", 33);
	set("attitude", "peaceful");
	 set("vendor_goods", ([
           "����":__DIR__"obj/yangrou",
           "��ͷ��":__DIR__"obj/zhutou",
           "ţβ":__DIR__"obj/niuwei",
           "����":__DIR__"obj/marou",
           "¿��":__DIR__"obj/lvrou",
           "ţ��":__DIR__"obj/niurou",
            ]));
   
	set("str", 25);
	set("int", 5);
	set("con", 25);
	set("kar", 25);
	set("combat_exp", 10000);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("blade", 50);
	set_temp("apply/defense", 10);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"����»������һ�ۣ������Ц��������������ˡ�\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/shzhdao")->wield();
}
void init()
{
	object me;
    	::init();
	add_action("do_vendor_list", "list");
 
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
void greeting(object me)
{
	if( (string)me->query("family/family_name") == "�䵱��" 
	|| (string)me->query("family/family_name") == "������" )
	{
		command("? "+me->query("id"));
		command("say �������׽�ɱ�����Ի磬"+RANK_D->query_respect(me)+
		"��ô�ܵ�������ˡ����ף����ף�\n");
		command("shake "+me->query("id"));
		command("say "+RANK_D->query_respect(me)+"������ذɡ�����Գ�����ˡ�����㡣\n");
		tell_room(environment(me),(string)me->query("name")+
	"������»�����ư��ϵĴ���������˳�ȥ.\n",({me, this_object()}));
		me->move("/d/jingcheng/baih4");
		return;
	}
	command("say "+RANK_D->query_respect(me)+"���Ⱑ��\n");
}
