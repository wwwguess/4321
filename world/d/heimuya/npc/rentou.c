inherit ITEM;

int decayed;

void create()
{
        set_name("������ͷ", ({ "rentou" }) );
        set("long", "����һ��������ͷ\n");
        set("unit", "��" );
	set("value",0);
	set("weight",1000);
}

//string short() { return query("id") + "��ͷ"; }

string query_autoload()
{
        return query("name");
}

void autoload(string arg)
{
 set("name",arg);
}

