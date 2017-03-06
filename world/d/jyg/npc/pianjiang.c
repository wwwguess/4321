// captain.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��ƫ��", ({ "li pianjiang","pianjiang" }));
	set("gender", "����");
	set("age", 34);
	set("long",
        	"�����Ǵ�����С��פ�ذ��ڵ�ƫ����\n");

	set("attitude", "peaceful");

	set("str", 27);
	set("int", 25);

	set("combat_exp", 120000);

	set("inquiry", ([
		"����" : "�ȸ�Ǯ��˵�ɡ�\n",
		"������" : "ร��������������ľ�ʦ������󷨡�\n",
	]) );
	
	set("chat_chance", 8);
	set("chat_msg", ({
		"��ƫ��˵������û������Ҫ���Ұ���\n",
		"��ƫ��˵�����Ҷ���������ม�\n",
	}) );
	
	set("force", 700);
	set("max_force", 700);
	set("force_factor", 5);

	set_skill("dodge", 70);
	set_skill("sword", 70);
	set_skill("parry", 70);
	set_skill("force", 70);
	set_skill("unarmed", 65);
	
	setup();

	carry_object( __DIR__"obj/sword")->wield();
	carry_object( __DIR__"obj/armor")->wear();
}

int accept_object(object who, object ob)
{
        if ( !ob->value() ) {
        	command("say ��....��hank ��ou!!!");
                command("grin");
        //        call_out( (: destruct :), 1, ob);
                return 1;
        }
                                                                                
	if ( !who->query("marks/��Ӫ") ) {
		if( ob->value() >=3000 ) {
			say("��ƫ��˵��:���Ѱ������������ˣ��ӽ����������"
				"�س���Ӫ���ˡ�\n");
			who->set("marks/��Ӫ",1);
			return 1;
		} else {
			say("��ƫ��˵��:��ĳ��ⲻ��ร��ٶ�ɵ�ɡ�\n");
			return 1;
		}
	} else
		say("��ƫ��˵��:Ŷร��������İ�������лл���ˡ�\n");
	
	return 1;
}

