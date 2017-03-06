// write by dfbb@hero
// 1/25/96
#include <ansi.h>
inherit NPC;
inherit F_QUEST;

void create()
{
	set_name("����ͤ", ({ "yang lian ting", "yang" }));
	set("title",HIR "��"+HIB"��"+HIY "���" NOR +"�ܹ�");	
	set("long", 
		"һ��������˼�Ĵ�,�ָ���׳,�·�����\n");
	set("gender", "����");
	set("age", 21);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_kee", 500);
	set("max_gin", 500);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 10);
	set("combat_exp", 15000);
	set("score", 6000);

	set_skill("force", 10);
	set_skill("tianmo-dafa", 10);
	set_skill("dodge", 10);
	set_skill("mo-shan-jue", 10);
	set_skill("strike", 10);
	set_skill("mo-zhang-jue", 10);
	set_skill("parry", 10);
	set_skill("halberd", 10);
	set_skill("literate", 50);

	map_skill("force", "tianmo-dafa");
	map_skill("dodge", "mo-shan-jue");
	map_skill("strike", "mo-zhang-jue");
	map_skill("halberd", "mo-ji-jue");
	map_skill("parry", "mo-ji-jue");

	prepare_skill("strike", "mo-zhang-jue");

	create_family("�������", 15, "�ܹ�");

	setup();
	carry_object("/obj/cloth")->wear();
	
}

int accept_fight(object me)
{
        command("say ��������!!");
        command("grin");
        return 0;
}

int accept_kill(object killer)
{

        int i;
        object *ob,me;
        me=this_object();
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( ob[i]->query("family/family_name")!="�������")continue;
                if( ob[i]->query("id")==killer->query("id")) continue;
                if( userp(ob[i]) ) ob[i]->kill_ob(killer);
                else if( !ob[i]->is_killing(killer) )
		ob[i]->kill_ob(killer);
                ob[i]->set_leader(killer);
                write(ob[i]->query("name")+ "���:"+HIY 
                "��С��, ��Ȼ��ɱ����������̵���,��ȥ����!\n" NOR);
        }
        return 1;
}

void init()
{
        add_action("do_gogo", "go");
        add_action("do_none", "north");
	add_action("give_quest","quest");
        ::init();
}

int do_gogo(string arg)
{
        object me;
        me = this_player();
        if( (arg == "north" )&&(!query("is_here")))
        {
         write("��������·������ͤ��ס�� ��\n");
	 command("say �����ص�,�㲻�ܽ�ȥ");
         return 1;
        }
        return 0;
}
 
        
int do_none()
{
        return 1;
}
               
