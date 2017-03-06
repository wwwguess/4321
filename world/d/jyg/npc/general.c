// general.c

#include <ansi.h>

inherit NPC;

//#define PATH "/u/t/tnn/canyon/camp2"
#define PATH "/d/shhg/camp2"

void create()
{
	set_name("��ȥ��", ({ "sb general","sb","general" }) );
	set("title", "�����ɵ��ߴ�����");
	set("nickname", YEL "ɨ���󽫾�" NOR);
	set("gender", "����");
	set("age", 34);
	set("long",
        	"��ȥ��������ò����,�����Ƕ�ı,���¸ɾ�����,\n"
        	"��ʮ��ͷ�ͳ�Ϊ�������������˾�����ɨ���󽫾���\n");

	set("attitude", "peaceful");
        create_family("������",7,"����");
	set("str", 29);
	set("int", 28);
	set("per", 18);

	set("inquiry",([
		"������" : "���۾��Ѵ�����������Ǽ����ء�\n",
		"�󱸱�" : "�Ҳ��������µģ���������ҡ�\n",
		"������" : "�������������������⣬������鰡��\n",
//		"ӡ��" : "����ô֪���ģ��������Ұɣ��ҵ������������\n",
	]) );
	set("force", 2100);
	set("max_force", 2100);
	set("force_factor", 20);
	set("max_gin", 200);
	set("eff_gin", 200);
	set("gin", 200);
	set("max_sen", 200);
	set("eff_sen", 200);
	set("sen", 200);
	
	set("combat_exp", 950000);

        set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "move.hasten" :),
//		(: exert_function, "recover" :)
	}) );
	
	set_skill("sword", 100);
	set_skill("mystsword", 85);
	set_skill("force", 101);
	set_skill("mysterrier", 80);
	set_skill("parry", 70);
	set_skill("dodge", 60);
	set_skill("move", 60);
	set_skill("unarmed", 80);
	set_skill("music", 85);
	
	map_skill("sword", "mystsword");
	map_skill("parry", "mystsword");
	map_skill("force", "mystsword");
//	map_skill("unarmed", "celestrike");
	map_skill("dodge", "mysterrier");
	
	
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
