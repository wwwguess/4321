
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("ѩ���", ({ "xuerui", "master","master xuerui" }) );
        set("gender", "Ů��" );
        set("title", "���齣��");
        set("age", 26);
        set("int", 30);
        set("per", 30);
        set("apprentice_available", 50);
        create_family("��ѩɽׯ", 1, "Ůׯ��");
	set("long",
		"ѩ�����ʮ���꿪ʼ�ͺͰ��������������������˵����ϱڣ�\n"
		"�����޵С���������������ʢ֮ʱ���ֺ�Ȼ�˳������������ڴˡ�\n"
		);
        set("force_factor", 90);
        set("max_gin", 1000);
        set("max_kee", 2500);
        set("max_sen", 1000);
        set("eff_gin", 1000);
        set("eff_kee", 2500);
        set("eff_sen", 1000);
        set("gin", 1000);
        set("kee", 3000);
        set("sen", 1000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);

        set("combat_exp", 4000000);
        set("score", 40000);
        set_skill("strike", 100);
        set_skill("sword", 150);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);
        set_skill("throwing", 100);
       set_skill("perception", 100);


	set_skill("meihua-shou", 100);
	set_skill("deisword", 150);
	set_skill("qidaoforce", 150);
	set_skill("fall-steps", 100);

        prepare_skill("strike", "meihua-shou");
	map_skill("strike", "meihua-shou");
        map_skill("sword", "deisword");
        map_skill("force", "qidaoforce");
        map_skill("parry", "deisword");
        map_skill("dodge", "fall-steps");

	setup();
	carry_object("/d/resort/obj/yellowcloth")->wear();
        carry_object("/d/resort/obj/msword");
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
                command("say ��ׯ�������Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "Ů��" )
          {      command("say ��ֻ��Ů���ӣ��㻹��ȥ���ҵ����Ӱɣ�");
          }
        else {

                command("smile");
                command("say ���պ���д�ɣ�");
                command("smile");
                command("recruit " + ob->query("id") );
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "legend");
        add("apprentice_availavble", -1);
}
int accept_fight(object me)
{
        object xiaocui;
        if( objectp(xiaocui = present("cui", environment(this_object()))) && living(xiaocui))
        {
        command("smile");
        command("say ������С�����ɡ�");
        return 0;
        }
        else
                command("sigh");
                command("ѩ��������ĴӴ������վ���������������е���ɰ����");
                command("wield wangsword");
                command("say �룡");
                call_out("do_unwie", 3);
                return 1;
}

int do_unwie()
{
	if( !this_object()->is_fighting()) 
	{	
		command("unwield wangsword");
                message_vision("$N����豭ǳ�һ�ڣ�������������������һ�ۣ�����������ϡ�\n", this_object());
                command("smile");
		return 1;
	}
	else
		call_out("do_unwie", 3);
}
void init()
{
        add_action("do_killing", "kill");
        add_action("give_quest", "quest");
}

int do_killing(string arg)
{

        object player, victim, weapon;
        string name;
        player = this_player();
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = victim->name();
                if( name == "����")
                {
                message_vision("$N����üͷ��\n", this_object());
                message_vision("$N�ӳ�Ƥ�����г��һ��ֻ����ָ����ݼ����������С�\n", this_object());
                weapon = present("wangsword", this_object());
                weapon->wield();
                this_object()->kill_ob(player);
                player->kill_ob(this_object());
                call_out("do_unwie", 3);
                return 0;
                }
                if( name == "ѩ���")
                {
                message_vision("$N����üͷ��\n", this_object());
                message_vision("$N�ӳ�Ƥ�����г��һ��ֻ����ָ����ݼ����������С�\n", this_object());
                weapon = present("wangsword", this_object());
                weapon->wield();
                call_out("do_unwie", 3);
                return 0;
                }
                return 0;
        }
        return 0;
}

// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"��$Nһҡͷ��˵���� ����Ǯ��ʲô����\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"��$N̾�˿�����˵���� ��ú�ѧѧ������Ҫ����ɣ�\n" ,who);
    who->set("quest",0);
    return(0);
}


