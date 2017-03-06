//hufei.c
//by dwolf

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(YEL"���"NOR, ({"hu fei", "hu" }));
        set("title", HIW"ѩɽ�ɺ�"NOR);
        set("long",
                "����һ�����Ӹߴ��൱Ӣ�����������ˡ�\n"
        );

        set("gender", "����");
        set("rank_info/respect", "�ɺ�");

        set("attitude", "heroism");
        
        set("inquiry",([
                "������"  : "�������ݣ����Ǹ�С����.",
		"��������" : "��Ҫ�������ȵý������У���ͬ��(nod)��", 
        ]));

        set("age", 30);
        set("shen_type", 10);
        set("str", 35);
        set("int", 30);
        set("con", 30);
        set("kar", 35);
	set("per", 30);
        set("max_kee", 3000);
        set("max_gin", 1000);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 300);
        set("combat_exp", 1000000);
        set("score", 1000000);
        set("apply/attack",  200);
        set("apply/defense", 200);

        set_skill("force", 200);
        set_skill("unarmed", 150);
        set_skill("blade", 200);
        set_skill("dodge", 250);
        set_skill("parry", 150);
      
        setup();
      
        carry_object(__DIR__"obj/hublade")->wield();
        carry_object(__DIR__"obj/hupi")->wear();
}

void init()
{
	::init();
	add_action("do_nod", "nod");
}


int do_nod()
{
	mapping guild;

	if( !this_player()->query("can_speak") || !(int)this_player()->query("mark/С��") 
|| !this_player()->query("mark/����") ) 
		return notify_fail("���С�");
	else {
/*	if( arg== "test" ) {*/
	say("\n��쳵��˵�ͷ��˵�����ܺã����ǵ�һ��....\n\n");
	COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
	if( (int)this_player()->query("kee") < 0 
	|| !present(this_player(), environment())) {
	say("���̾�˿�����˵��������һ�ж��Ų����������Բ�����....\n");
		return 1;
		}
		say("\n���˵�������ǵڶ���....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0 
		|| !present(this_player(), environment())) {
			say("��쳡��ߡ���һ����˵��������������\�಻�����ļһ�....\n");
			return 1;
		}
		say("\n���˵��������������....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0 
		|| !present(this_player(), environment())) {
			say("���̾������ϧ�����һ����ûͨ���������������ˡ�....\n");
			return 1;
		}
		say("\n��쳹�����Ц��˵��������ʹ���ȥ�����ӣ�\n\n");
		this_player()->move("/d/xueshan/heaven");
		this_player()->delete("mark/С��");
			return 1;
	}
		return 0;
}


