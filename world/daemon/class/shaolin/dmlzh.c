// dmlzh.c ��Ħ����
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();
void create()
{
	set_name("��Ħ����", ({ "da mo lao zu", "da","lao zu" }));
	//set("nickname", "��������ʦ");
        set("title",HIR "��"+HIB"��"+HIY "��" NOR + "��ʦ");
	set("long", "���������ɵĿ�ɽ��ʦ��Ħ����\n
		����ĸߴ�,��������֪�ж�����,Ŀ�����,���տȻ.\n");
	set("gender","����");
	set("age", 1000);
	set("attitude", "peaceful");
	set("cor", 101);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("cor", 50);
	
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                ("\n"+ RED "��Ħ����˵�������书��Ȼ����, ��Ҫ���������˼�������֮��!\n\n" NOR),
                (: exert_function, "hunyuan-yiqi" :),
		(: exert_function, "recover" :),
        }) );

	set("max_kee", 7000);
	set("max_gin", 7000);
	set("force", 10000);
	set("max_force", 8000);
	set("force_factor", 150);
	set("combat_exp", 30000000);
	set("score", 0);

	set_skill("force", 300);
	set_skill("hunyuan-yiqi", 300);
	set_skill("dodge", 300);
	set_skill("cuff", 300);
	set_skill("jingang-quan", 300);
	set_skill("sword", 300);
	set_skill("parry", 300);
	set_skill("damo-jian", 300);
	set_skill("literate", 300);
   set_skill("shaolin-shenfa",300);
 /*    set_skill("yijing-xinfa",200); */

	map_skill("force", "hunyuan-yiqi");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");
	map_skill("sword", "damo-jian");
	map_skill("dodge", "shaolin-shenfa");

	prepare_skill("cuff", "jingang-quan");

	create_family("������", 1, "��ʦ");
	setup();

       carry_object("/d/shaolin/obj/jingang-zhao")->wear();
	set("inquiry", ([
		"������"     : (: ask_me :),
	]));

	set("count", 1);

	setup();

}

void init()
{
	object me, ob;
	mapping fam;

	me = this_player();
	ob = this_object();

	::init();
	if( interactive(me) ) 
	{
		if ( mapp(fam = me->query("family")) && fam["family_name"] == "������" 
                && fam["generation"] == 35 ) 
		{
	                me->set_temp("fighter", 1);
			return;
		}

		if ( mapp(fam = me->query("family")) && fam["family_name"] == "������" 
		&& fam["generation"] > 35 		
		&& me->query("kee") < 50 ) 
		{
			me->move("/d/shaolin/damodong");
			me->unconcious();
			return;
		}

		COMBAT_D->do_attack(ob, me, query_temp("weapon") );
		
		me->set_temp("fighter", 1);

		ob->fight_ob(me);
		me->fight_ob(ob);

		call_out("halt", 10);

		return;
	}

	return;
}

void halt()
{
	command("say �ðɣ����ס�֣� ����һ���ʲô��Ҫ˵��");
	command("halt");
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if ( !this_player()->query_temp("fighter") 
	||    this_player()->query("combat_exp") < 50000 )
	{
		command("say ���󱲣����δ�ɣ����Ҵ��뱾��ʥ�أ������������������㣡");
		this_object()->kill_ob(this_player());
		this_player()->kill_ob(this_object());
	}

	if ( present("she lizi", this_player()) )
		return RANK_D->query_respect(this_player()) + 
               "�����ϲ����Ѿ���������������̰�����У�";
	if (query("count") < 1)
		return "��Ǹ���������ˣ��������Ѿ�����ȡ���ˡ�";

	ob = new("/d/shaolin/obj/she-lizi");
	ob->move(this_player());

	add("count", -1);

	message_vision("\n��Ħ���ͷ���ӻ���ȡ�������ӽ���$N��\n\n", this_player());

	return "���Ȼ���ҵ���,Ҳ�����컯��,�����������ҷ���٤Ĳ�������,���Ҫ�ú���ϧ.";
}
#include "/class/shaolin/damo.h"
