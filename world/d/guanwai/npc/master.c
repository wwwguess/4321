
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("葛伦", ({ "master gelun", "master","gelun" }) );
	set("gender", "男性" );
	set("age", 99);
	set("int", 30);
        set("apprentice_available", 20);
        create_family("大招寺", 20, "主持");
	set("long",
		"葛伦高僧已在大招寺主持多年。男女弟子遍布关外。\n"
		);
	set("inquiry", ([
		"舍利子": "嗯....舍利子.....在舍利塔里。\n",
		"普松": "普松在大招寺的木屋里。",
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
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本主持今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
                command("smile");
                command("say 很好，很好，很好。");
                command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lama");
        add("apprentice_availavble", -1);
}

