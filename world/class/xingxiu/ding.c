#include <ansi.h>
// ding.c ������

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void consider();

void create()
{
	set_name("������", ({ "ding chunqiu", "ding" }));
	set("title",MAG "������" NOR + YEL "��ɽ" NOR + MAG "��ʦ" NOR);
        set("nickname", RED "�����Ϲ�" NOR);
	set("long", 
		"�����������ɿ�ɽ��ʦ����������ʿ���ʹ���������Ϲֶ����\n"
		"��������������ò���棬�ɷ���ǡ�\n");
	set("gender", "����");
	set("age", 60);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_kee", 4000);
	set("max_gin", 300);
	set("max_sen", 300);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 100);
	set("combat_exp", 1500000);
        set("shen",-150000);
	set("score", 400000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );

	set_skill("force", 100);
	set_skill("huagong-dafa", 150);
	set_skill("dodge", 150);
	set_skill("zhaixinggong", 150);
	set_skill("strike", 100);
	set_skill("xingxiu-duzhang", 150);
	set_skill("parry", 100);
	set_skill("staff", 100);
	set_skill("tianshan-zhang", 150);
	set_skill("literate", 80);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu-duzhang");
	map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "xingxiu-duzhang");

	create_family("������", 1, "��ɽ��ʦ");
	set("class", "taoist");

	setup();
//      carry_object("/clone/weapon/changjian")->wield();
}

void init()
{

        object me, ob;
        mapping fam;

        add_action("do_flatter", "flatter");
	add_action("give_quest","quest");
        ::init();

        ob = this_player();
        me = this_object();
        if ( (int)ob->query("shen") >=0 && ((fam = ob->query("family")) && fam["master_id"] == "ding chunqiu"))
        {
                command("say ����ɱ��ͬ�����ˣ��������������ʦ����\n");
                command("expell "+ ob->query("id"));
        }
}


void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > -1000) {
                command("say ����Խ����Խ��׵������Ե׵ġ�");
                return;
        }

        if( me->query_temp("pending/flatter") ) {
                command("say ����˲������ɷ�����������������㣿");
                return;
        } else {
                command("say ���������ɱ������������ʥ����ô������");
                message_vision("�����Ϲ�΢��˫�ۣ������룬һ����������(flatter)�����ӡ�\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        }
}

int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("��˵����ʲô��\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N����˵����" + arg + "\n", this_player());
        if( strsrch(arg, "��������") >=0 && (strsrch(arg, "�������") >=0
         || strsrch(arg, "�������") >=0 || strsrch(arg, "�Ž��ޱ�") >=0 )) {
                command("smile");
                command("say �⻹��ࡣ\n");
                command("recruit " + this_player()->query("id"));
	if((string)this_player()->query("gender")!="Ů��")
        	this_player()->set("title",HIR "������" NOR + GRN +"аʿ" NOR);
        else
		this_player()->set("title",HIR "������" NOR + GRN +"��Ů" NOR);
        } else {
                command("say ����˲������ɷ�����������������㣿");
        }
        return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}

// �������ɣ�������أ��������Ž��ޱ�

void consider()
{
        int i=random(4);
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        if (i==3)
                command("exert maxsuck " + target->query("id"));
        if (i==2)
                command("exert neilisuck " + target->query("id"));
        if (i==1)
                command("exert jingsuck " + target->query("id"));
        if (i==0)
                command("exert qisuck " + target->query("id"));
}
