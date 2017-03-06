inherit NPC;

#include <ansi.h>
 
void create()
{
        set_name("������", ({ "shinyu","shin" }) );
        set("title", "����ׯ����������");
        set("gender", "Ů��" );
        set("age",17);
        set("long", @TEXT
TEXT
);
       set("class", "dancer");
        set("combat_exp", 5000000);
        set_skill("unarmed",20);
        set_skill("dodge", 100);
        set_skill("spring-blade", 100);
        set_skill("blade",100);
        map_skill("blade", "spring-blade");
        set_skill("force",100);
//
        set_skill("force",100);
        set("force",4500);
        set("max_force",4500);
        set("force_factor",20);
        set("attitude", "friendly");
        setup();
//carry_object("/u/s/seraph/latemoon/obj/yu_blade")->wield();
}

void init()
{
       object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("gender") == "����" ) {
		say( HIY "�����󺰣� ι! ��̨! �ⲻ׼���˽���! \n"  NOR );
		say( HIR "����������ȡ��һ�ѷۺ�ɫϸ��������ȥ��\n" NOR );
		say( HIY "����һ�������������˳�ȥ��\n" NOR );
        command("close door");
        ob->apply_condition("rose_poison", 10);
		ob->receive_damage("gin",50);
		ob->receive_damage("kee",100);
        ob->receive_damage("sen", 50);
		ob->move("/d/latemoon/room/flower1");
		return;
	}
    command("close door");
    return;
}

