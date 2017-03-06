
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "master gelun", "master","gelun" }) );
	set("gender", "����" );
	set("age", 99);
	set("int", 30);
        set("apprentice_available", 20);
        create_family("������", 20, "����");
	set("long",
		"���׸�ɮ���ڴ��������ֶ��ꡣ��Ů���ӱ鲼���⡣\n"
		);
	set("inquiry", ([
		"������": "��....������.....���������\n",
		"����": "�����ڴ����µ�ľ���",
	]) );
          set("combat_exp", 5000000);
        set("max_kee",400);
        set("max_gin",400);
        set("score", 90000);
        set_skill("unarmed", 300);
        set_skill("staff", 400);
        set_skill("force", 300);
        set_skill("parry", 300);
        set_skill("literate", 150);
	set_skill("iron-cloth", 300);
	set_skill("magic", 150);

	set_skill("bloodystrike", 300);
	set_skill("cloudstaff", 300);
	set_skill("bolomiduo", 150);
	set_skill("buddhism", 300);
	set_skill("essencemagic", 300);
        set_skill("jin-gang", 300);


	map_skill("unarmed", "bloodystrike");
        map_skill("staff", "cloudstaff");
        map_skill("force", "bolomiduo");
        map_skill("parry", "cloudstaff");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("magic", "essencemagic");

	setup();
	carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/9staff")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �����ֽ����Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
}
void do_recruit(object ob)
{
                command("smile");
                command("say �ܺã��ܺã��ܺá�");
                command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lama");
        add("apprentice_availavble", -1);
}

