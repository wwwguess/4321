// qinge.c
//by dwolf

#include <ansi.h>
inherit NPC;

string tell_story();
string ask_me();
string *make_msg = ({  
    HIW"\ͣ��Ƭ�̣��ظ�˵���������ˣ��Ҿ͸���˵�˰ɡ���\n\n"NOR,    
    HIG"������һ���������ĵ��£�������ʮ���꣬����Ҫһ��Ϊ�졣\n\n"NOR,
    HIG"��ô��������ĸ��˵���������µ�һ���ˣ�������Ȼ��Ҳ����������衣\n\n"NOR,
    HIG"�����Һ���Ȼһ�����飬������������������������Ǳ����ǳ��Ҹ������� \n\n"NOR,
    HIG"һ��ͻȻ�����콵��������������꣬��Ӧ�������޹����룬ȥѵ��������û  \n\n"NOR,
    HIG"�뵽�����廢�ô˻��ᣬ��������ĸ�ӣ����쵰���������ޣ�����Ȼ������  \n\n"NOR,
    HIG"�ӣ��ᵶ�Ծ����ǰ�һ�ʧ��֮�࣬��Ȼ���������������ˡ����ҵõ���Ϣ  \n\n"NOR,
    HIG"����ҹ�ϱ�������������������Ȼ��ȥ��������٣��ң���������------- \n\n"NOR,
    HIG"˵���������λ���������ѽ���ס����������\n\n"NOR
});

void create()
{
	set_name(YEL"�ظ�"NOR, ({ "qin ge", "qin" }));
	set("gender", "����");
	set("title", RED"���鵶��"NOR);
	set("age", 40);
	set("long",
        	MAG"���е���ͣ�����ȥ�ܳ��죬���˱�����ɣ�����ӡ�����ü����������ȥ
�������¡�\n"NOR);

	set("attitude", "peaceful");

	set("str", 40);
	set("int", 40);

	set("combat_exp", 2000000);

	set("inquiry", ([
		"����" 	: (: ask_me :),
		"�����"  : (: tell_story :),
	]) );  
	set("count", 1);
	
	set("chat_chance", 10);
	set("chat_msg", ({
		HIM"�ظ���������ǰ�������ˣ��󲻼����ߣ�֪����ν�����ǣ���֪����ν�Һγ�� \n"NOR,
		HIM"�ظ�̾�������������Ƴ��ұ���һ�뽭�����´ݡ���\n"NOR,
	}) );
	
	set("force", 700);
	set("max_force", 700);
	set("force_factor", 20);

	set_skill("dodge", 200);
	set_skill("blade", 200);
	set_skill("parry", 200);
	set_skill("force", 200);
	set_skill("unarmed", 100);
		
	setup();

	carry_object("/d/jingcheng/npc/obj/ddblade.c")->wield();
	carry_object("/d/jingcheng/npc/obj/cloth")->wear(); 
}      

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (query("count") < 1)
		return RED"��Ǹ���������ˣ��Ѿ����˰��Ҵ����ˡ�"NOR;

/*	ob = new("/d/jingcheng/npc/obj/yupei.c");     */
	ob = new(__DIR__"obj/letter.c");
	ob->move(this_player());

	add("count", -1);

	message_vision(YEL"\n�ظ�̾��һ���������ͷ������ǰȡ��һ����Ž���$N��\n\n"NOR, this_player());

	return YEL"���Ȼ֪�����ҵ��£�Ҳ����Ե������ž͸����ˡ���������\n"
		"������͸���������һֱ�����������������ź�С�ػ��Ƽ����ҡ�"NOR;
}


string tell_story()
{
	object who;
    who=this_player();
	call_out( "make_stage", 2, who, 0 );
	return CYN"�ظ趢���㿴���ƺ�Ҫ�����㡣������ô����������أ���\n"NOR;
}

void make_stage(object who,int stage)
{
	tell_object(who,make_msg[stage]);
	if (++stage < sizeof(make_msg) ) {
		call_out( "make_stage", 2, who, stage);
		return;
	}
	return;
}
         
		
