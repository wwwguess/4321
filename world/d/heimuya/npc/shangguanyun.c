// rysj master.c
// write by dfbb@hero
// 1/25/96
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();
string tang="������";
void create()
{
	set_name("�Ϲ���", ({ "shanguan yun", "yun" }));
	set("title",HIR "��"+HIB"��"+HIY "���" NOR + GRN+ tang+ NOR +"����");	
	set("long", 
		"���������ʮ������ݳ���ɫ����\n");
	set("gender", "����");
	set("age", 41);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 50);
	set("combat_exp", 150000);
	set("score", 60000);

	set_skill("daguanming", 100);
	set_skill("force", 100);
	set_skill("tianmo-dafa", 100);
	set_skill("dodge", 100);
	set_skill("mo-shan-jue", 100);
        set_skill("strike", 100);
	set_skill("mo-zhang-jue", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("literate", 50);
	set_skill("mo-jian-jue", 100);


	map_skill("force", "tianmo-dafa");
	map_skill("dodge", "mo-shan-jue");
        map_skill("strike", "mo-zhang-jue");
	map_skill("parry", "mo-jian-jue");
	map_skill("sword", "mo-jian-jue");

        prepare_skill("strike", "mo-zhang-jue");

	create_family("�������", 15, "����");

	set("inquiry", ([
		"�ؼ�" : (: ask_me :),
	]));

	set("book_count", 1);

	setup();
	carry_object("/d/heimuya/obj/sword")->wield();
	carry_object("/obj/cloth")->wear();
	
}

void attempt_apprentice(object ob)
{
	if(this_player()->query("family/family_name")!="�������")
	 {
          write( RANK_D->query_respect(this_player()) +
                "������ذ�!�Ҳ��ս���֮��\n");
	  return;	
	 }
        if(this_player()->query("whichtang")!=0&&this_player()->query("whichtang")!=tang)
	 {
	   write( RANK_D->query_respect(this_player()) +
                "�㲻�Ǳ��õ���,��ذ�\n");
           return;
	 }
	command("say �ðɣ��Ҿ��������ˡ�\n");
	command("say �ӽ�����,���������"+tang+"��һԱ��!\n");
	command("recruit " + ob->query("id"));
	this_player()->set("whichtang",tang);
        this_player()->set("title",HIR "��"+HIB"��"+HIY "���" NOR + GRN +tang+ NOR
+"����");
	
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (this_player()->query("family/family_name")!="�������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ����̵��ڹ��ķ����ڴ˴���";
	add("book_count", -1);
	ob = new("/d/heimuya/obj/force_book");
	ob->move(this_player());
	return "�ðɣ��Ȿ����ħ�󷨡����û�ȥ�ú����С�";
}
