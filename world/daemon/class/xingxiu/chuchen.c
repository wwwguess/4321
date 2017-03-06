// shihou.c ������

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("������", ({ "chuchen zi", "chuchen" }));
        set("title",MAG "������" NOR + YEL "аʿ" NOR);
        set("nickname", RED "�����ɰ�ʦ��" NOR);
	set("long", 
		"�����Ƕ�����İ˵��ӳ����ӡ�\n"
		"����Ű��֣��������յĸ����ֳ����ء�\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 15);
	set("con", 28);
	set("dex", 28);
	set("per", 18);
	
	set("max_kee", 300);
	set("max_gin", 300);
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 15);
	set("combat_exp", 100000);
	set("score", 20000);

	set_skill("force", 60);
//	set_skill("huagong-dafa", 4);
	set_skill("dodge", 60);
	set_skill("zhaixinggong", 50);
	set_skill("strike", 50);
	set_skill("xingxiu-duzhang", 20);
	set_skill("parry", 50);
	set_skill("staff", 80);
  	set_skill("tianshan-zhang", 80);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingxiu-duzhang");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "xingxiu-duzhang");

	create_family("������", 2, "����");

	setup();
  	carry_object("/obj/weapon/gangzhang")->wield();
}

void init()
{
        object ob;
        mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                myfam = (mapping)ob->query("family");
                if ((!myfam || myfam["family_name"] != "������") &&
                        (!wizardp(ob))) {
                        remove_call_out("do_killing");
                        call_out("do_killing",4,ob);
                }
        }
}

void do_killing(object ob)
{
	if (!ob || environment(ob) != environment())
                return;
        this_object()->kill_ob(ob);
}

void attempt_apprentice(object ob)
{
	command("say ���ɻ�û��������ͽ�ء�");
	//command("recruit " + ob->query("id"));
}
