// general.c

#include <ansi.h>

inherit NPC;

//#define PATH "/u/t/tnn/canyon/camp2"
#define PATH "/d/canyon/camp2"

void create()
{
	set_name("��͢��", ({ "master general","master","general" }) );
	set("title", "��а�ɵ�ʮ��������");
	set("nickname", YEL "����󽫾�" NOR);
	set("gender", "����");
	set("age", 45);
	set("long",
        	"�ݹ���������嵶�����彣���������������߳����磬����\n"
        	"����������ʱͬ�ʹ���а��������ͬ��һʦ���书\���費�ڴ�\n"
        	"��а֮�£���־��ͬ������˾�ʦ�书\��һ�����˳��۵���\n"
        	"���󽫾���\n");

	set("attitude", "peaceful");

	set("str", 29);
	set("int", 28);

	set("inquiry",([
		"��ʯ����" : "���۾��Ѵ�����������ǻ�ʯ���ڡ�\n",
		"�󱸱�" : "�Ҳ��������µģ���������ҡ�\n",
		"������" : "�������������������⣬������鰡��\n",
		"ӡ��" : "����ô֪���ģ��������Ұɣ��ҵ������������\n",
	]) );
	set("force", 1800);
	set("max_force", 1800);
	set("force_factor", 20);
	set("max_gin", 200);
	set("eff_gin", 200);
	set("gin", 200);
	set("max_sen", 200);
	set("eff_sen", 200);
	set("sen", 200);
	
	set("combat_exp", 900000);

        set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );
	
	set_skill("sword", 80);
	set_skill("six-chaos-sword", 85);
	set_skill("force", 80);
	set_skill("celestial", 80);
	set_skill("parry", 50);
	set_skill("dodge", 60);
	set_skill("pyrobat-steps", 60);
	set_skill("unarmed", 80);
	set_skill("celestrike", 85);
	
	map_skill("sword", "six-chaos-sword");
	map_skill("parry", "six-chaos-sword");
	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("dodge", "pyrobat-steps");
	
	
	setup();

	carry_object( __DIR__"obj/broken_sword")->wield();
//carry_object( __DIR__"obj/broken_sword")->wield();
	carry_object( __DIR__"obj/cloud_armor")->wear();

}

int accept_object(object who,object ob)
{
	object obj;

	if ( (string)ob->name() == "[1;33mӡ��[0m") {
		command("say ����лл���ˡ�");
		command("smile");
		command("say Ϊ�˴�л�㣬��ѹŽ����㣬��������ɡ�");
//		obj=new(__DIR__"obj/old_sword");
                obj=new("/d/canyon/npc/obj/old_sword");
		obj->move(who);
//		call_out( (: destruct :), 1, ob);
 		return 1;
 	}
 	
	if ( (string)ob->name() == "ӡ��" ) {
		command("say ���ø��ҵ���ʲô������!");
 		command("say ���������ֶ�����ƭ��");
		command("say ���ҹ���ȥ");
 		who->set_temp("����/kick", 1);
		who->move(PATH);
		return 0;
	}
	
	if ( !ob->value() ) {
		command("say ��....��hank ��ou!!!");
		command("grin");
//		call_out( (: destruct :), 1, ob);
		return 1;
	}
	
	command("say ��������лл���ˡ�");
	return 1;
}
