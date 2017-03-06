// Mon  08-21-95

inherit NPC;

void do_sigh();
string about_jade();
void do_say_one();
void do_say_two();
string about_theft();
 
void create()
{
        seteuid(getuid());
        set_name("�峤", ({"elder", "oldman", "man"}));
        set("long", @TEXT
������ǰ����һ���������ݵ�����.
TEXT
        );
        set("gender","����");
        set("age",95);
        set("combat_exp",500);
        set("attitude","friendly");
        set("chat_chance",10);
        set("inquiry", ([
        "����" : (: about_jade :),
        "��С͵" : (: about_theft :),
        ]) );
        set("chat_msg", ({
        (: do_sigh :),
        (: do_say_two :),
        (: do_say_one :) }) );
        setup();
        carry_object("/obj/cloth")->wear();
}

void do_say()
{
    command("sigh");
    return;
}

void do_say_one()
{
    command("say ���Ĳ���.... ");
    command("sigh elder");
    return;
}

void do_say_two()
{
    command("say ���岻����.... ");
    command("sigh elder");
    return;
}

string about_jade()
{
    command("sigh");
    command("say ������... ǰ������С͵, ��Ĳ��þ������.");
    command("hmm");
    return "ϣ����Ҫ������֮������.";
}

string about_theft()
{
    this_player()->set_temp("asked_theft",1);
    command("sigh");
    command("say ������.... ");
    command("say ��ʯ�����û�з������԰�, ������ʱ... ");
    command("sigh");
    return "�����������Щİ����, ��֪����������û�й�ϵ...";
}

