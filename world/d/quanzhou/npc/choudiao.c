// Eric 96.9.25

#include <ansi.h>


inherit NPC;

int ask_me();
int getin(object me, object ob);

void create()
{
        set_name(YEL"���"NOR, ({ "chou diao", "chou", "diao" }));
        set("long", "
�˵��������ޣ����˻��ߣ������ª֮����ȫ����ë������
�䣬˫����֣���ʱ�������ȴ����̣���֪��η��衣
ֻ�Ǹ�������������һ���������š�\n");
        set("gender", "���˰���");
        set("rank_info/respect", "����");
        set("age", 100);
        set("str", 80);
        set("dex", 85);
	set("shen_type", 1);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set_temp("apply/attack", 100);
        set_temp("apply/armor", 100);
           set("max_kee", 2000);
        set("eff_qi", 2000);
        set("kee", 2000);
        set("max_gin", 2000);
        set("gin", 2000);
        set("force", 2000);
        set("max_force", 2000);
        set("jiali", 30);

        set_skill("claw",200);
        set_skill("dodge",  200);
        set_skill("move",300);
        set_skill("parry",  200);

        map_skill("dodge", "boji");
        map_skill("parry", "boji");
        map_skill("claw", "boji");
        set_skill("force", 200);
        set("jiali",50);

        set("combat_exp", 500000);


        set("inquiry", ([
	    "�ϱ���" : (: ask_me :),
       ]) );

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
		(: this_object(), "random_move" :),
		"����������ͷ�����ߺ�������\n",
		"���ת��ͷ�������������ͺ���\n" }) );

}

int ask_me()
{

	object me,ob;

 	me = this_object();
	ob = this_player();

	if ( file_name(environment(me)) == "/d/quanzhou/shangu" ) {
		   message("vision",
   BLU "�����һ���������Ӻܸ��ˡ�\n"
   BLU "����ת�����ӣ������ߵĲݴ���ȥ��\n"
   BLU "���ݷִ���ٲȻ��һ��ֻ��һ�˹���С·��\n"
   BLU "$N���ɼ��ظ������˹�ȥ��\n"
   NOR, environment(), me );

		me->move("/d/quanzhou/caocong");
		ob->move("/d/quanzhou/caocong");

	} else {
		   message("vision",
   HIY "������Ų��ӿ����㼸�ۣ���Ȼ����ʧ�����ˡ�\n"
   NOR, environment(), me );
	}

   return 1;
}
  
