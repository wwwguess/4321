// Mon  08-21-95

inherit NPC;
 
void create()
{
        int has_game;
        seteuid(getuid());
        set_name("������",({"old woman", "oldwoman", "woman"}));
        set("long", @TEXT
TEXT
        );
        set("gender","Ů��");
        set("age",74);
        set("combat_exp",55);
        set("attitude","friendly");
        set("chat_chance_combat", 55);
        set("chat_msg_combat", ({
        (: this_object(), "ask_for_help" :) }) );
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin",100);
}
 
void ask_for_help()
{
        object helper;
        helper = present("old man", environment(this_object()));
        if (!helper || helper->is_fighting()) return;
        tell_room(environment(helper), helper->name()+"�е�: �ð�,"+
        "�ҿ�������, ȥ����!\n", ({this_object(), helper}) );
        helper->kill_ob(query_temp("killer"));
        return;
}
 
void kill_ob(object ob)
{
        set_temp("killer",ob);
        ::kill_ob(ob);
}
