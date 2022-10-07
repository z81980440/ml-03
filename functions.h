#include "structs.h"

void init_origin();
void init_axis_point(int value, axis_point *axis_point);
point new_point(int x, int y);
void bind_point(point p);
void bind_point(int x, int y);
void set_current_origin(origin *origin);
void bind_x_axis(int val, axis_point *axis);
void bind_y_axis(int val, axis_point *axis);
void get_endpoint_x(int val, axis_point *axis, point *endpoint); // IF ENPOINT == NULL .. AXIS IS ENDPOINT.
void get_endpoint_y(int val, axis_point *axis, point *endpoint); // IF ENPOINT == NULL .. AXIS IS ENDPOINT.

origin *currentOrigin;

void set_current_origin(origin *origin)
{
    currentOrigin = origin;
}

point new_point(int x, int y)
{
    point p;
    p.x = x;
    p.y = y;
    return p;
}

void init_axis_point(int value, axis_point *axis_point)
{
    axis_point->value = value;
}

void init_origin()
{
}

void bind_point(point p)
{
    axis_point *axis_x;
    axis_point *axis_y;
    bind_x_axis(p.x, axis_x);
    bind_y_axis(p.y, axis_y);
    point *endpoint_x;
    point *endpoint_y;
    get_endpoint_x(p.x, axis_x, endpoint_x);
    get_endpoint_y(p.y, axis_y, endpoint_y);
    point *p1 = (point *)malloc(sizeof(point));

    if (endpoint_x != nullptr)
    {
        point * temp;
        temp = endpoint_x->next_point_x;
        endpoint_x->next_point_x = p1;
        p1->next_point_x = temp;
    } else {
        point * temp = axis_x->point;
        axis_x->point = p1;
        p1->next_point_x = temp;
    }

    if (endpoint_y != nullptr)
    {
        point * temp;
        temp = endpoint_y->next_point_y;
        endpoint_y->next_point_y = p1;
        p1->next_point_y = temp;
    } else {
        point * temp = axis_y->point;
        axis_y->point = p1;
        p1->next_point_y = temp;
    }
    
}

void bind_point(int x, int y)
{
    point p;
    p.x = x;
    p.y = y;
    bind_point(p);
}

void bind_x_axis(int val, axis_point *axis)
{
    // to be optimize
    axis_point *current = currentOrigin->x;
    axis_point *before;
    while (current != nullptr)
    {
        if (current->value > val)
        {
            break;
        }
        before = current;
        current = current->next_axis_point;
    }

    if (before == nullptr)
    {
        if (current != nullptr)
        {
            axis_point *a = (axis_point *)malloc(sizeof(axis_point));
            a->value = val;
            axis = a;
            currentOrigin->x = a;
            a->next_axis_point = current;
            return;
        }
        axis_point *a = (axis_point *)malloc(sizeof(axis_point));
        a->value = val;
        axis = a;
        currentOrigin->x = a;
        return;
    }

    if (current == nullptr)
    {
        axis_point *a = (axis_point *)malloc(sizeof(axis_point));
        a->value = val;
        axis = a;
        before->next_axis_point = a;
        return;
    }

    if (before->value == val)
    {
        axis = before;
        return;
    }

    axis_point *a = (axis_point *)malloc(sizeof(axis_point));
    a->value = val;
    axis = a;
    before->next_axis_point = a;
    a->next_axis_point = current;
}

void bind_y_axis(int val, axis_point *axis)
{
    // to be optimize
    axis_point * current = currentOrigin->y;
    axis_point * before;
    while (current != nullptr)
    {
        if (current->value > val)
        {
            break;
        }
        before = current;
        current = current->next_axis_point;
    }

    if (before == nullptr)
    {
        if (current != nullptr)
        {
            axis_point *a = (axis_point *)malloc(sizeof(axis_point));
            a->value = val;
            axis = a;
            currentOrigin->y = a;
            a->next_axis_point = current;
            return;
        }
        axis_point *a = (axis_point *)malloc(sizeof(axis_point));
        a->value = val;
        axis = a;
        currentOrigin->y = a;
        return;
    }

    if (current == nullptr)
    {
        axis_point *a = (axis_point *)malloc(sizeof(axis_point));
        a->value = val;
        axis = a;
        before->next_axis_point = a;
        return;
    }

    if (before->value == val)
    {
        axis = before;
        return;
    }

    axis_point *a = (axis_point *)malloc(sizeof(axis_point));
    a->value = val;
    axis = a;
    before->next_axis_point = a;
    a->next_axis_point = current;
}

void get_endpoint_x(int val, axis_point *axis, point *endpoint) {
    if(axis->point == nullptr ) {
        endpoint = nullptr;
        return;
    }

    point * current = axis->point;
    point * before;
    while (current->x < val)
    {
        before = current;
        current = current->next_point_x;
    }

    if(before == nullptr) {
        endpoint = nullptr;
        return;
    }

    endpoint = before;    
    
}

void get_endpoint_y(int val, axis_point *axis, point *endpoint) {
    if(axis->point == nullptr ) {
        endpoint = nullptr;
        return;
    }

    point * current = axis->point;
    point * before;
    while (current->y < val)
    {
        before = current;
        current = current->next_point_y;
    }

    if(before == nullptr) {
        endpoint = nullptr;
        return;
    }

    endpoint = before;    
    
}

